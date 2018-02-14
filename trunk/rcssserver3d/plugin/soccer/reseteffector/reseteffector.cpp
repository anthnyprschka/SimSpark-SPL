/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id$

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include "resetaction.h"
#include "reseteffector.h"
#include <soccerbase/soccerbase.h>
#include <agentstate/agentstate.h>
#include <cmath>
#include <oxygen/agentaspect/agentaspect.h>

using namespace boost;
using namespace oxygen;
using namespace salt;
using namespace std;

ResetEffector::ResetEffector() : oxygen::Effector()
{
}

ResetEffector::~ResetEffector()
{
    mNoiseRng.reset();
}

#ifdef __APPLE_CC__
bool
isfinite( float f )
{
    return f == f && f != f * 0.5f;
}
#endif

void
ResetEffector::PrePhysicsUpdateInternal(float /*deltaTime*/)
{
    if (
        (mAction.get() == 0) ||
        (mBody.get() == 0) ||
        (mGameState.get() == 0) ||
        (mAgentState.get() == 0) ||
        (mNoiseRng.get() == 0)
        )
    {
        return;
    }

    boost::shared_ptr<ResetAction> resetAction =
        dynamic_pointer_cast<ResetAction>(mAction);

    mAction.reset();

    if (resetAction.get() == 0)
    {
        GetLog()->Error()
            << "ERROR: (ResetEffector) cannot realize an unknown ActionObject\n";
        return;
    }


    Vector3f pos;
    pos[0] = 0.0; // resetAction->GetPosX()
    pos[1] = 0.0; // resetAction->GetPosY()

    float angle = 0.0; // resetAction->GetXYAngle()

    if (
        (! gIsFinite(pos[0])) ||
        (! gIsFinite(pos[1]))
        )
        {
            return;
        }

    // fix z coordinate
    pos[2] = mAgentRadius;

    boost::shared_ptr<Transform> agentAspect;
    SoccerBase::GetTransformParent(*this, agentAspect);
    if (agentAspect.get() == 0)
    {
        GetLog()->Error()
        << "ERROR: (ResetEffector) cannot get AgentAspect\n";
        return;
    }

    if (!SoccerBase::MoveAndRotateAgent(agentAspect, pos, angle))
        return;
}

boost::shared_ptr<ActionObject>
ResetEffector::GetActionObject(const Predicate& predicate)
{
  if (predicate.name != GetPredicate())
    {
      GetLog()->Error() << "ERROR: (ResetEffector) invalid predicate"
                        << predicate.name << "\n";
      return boost::shared_ptr<ActionObject>();
    }

  Predicate::Iterator iter = predicate.begin();

  float posX;
  if (! predicate.AdvanceValue(iter, posX))
  {
      GetLog()->Error()
          << "ERROR: (ResetEffector) float expected for parameter1\n";
      return boost::shared_ptr<ActionObject>(new ActionObject(GetPredicate()));
  }

  float posY;
  if (! predicate.AdvanceValue(iter, posY))
  {
      GetLog()->Error()
          << "ERROR: (ResetEffector) float expected for parameter2\n";
      return boost::shared_ptr<ActionObject>(new ActionObject(GetPredicate()));
  }

  float angle;
  if (! predicate.AdvanceValue(iter, angle))
  {
      GetLog()->Error()
          << "ERROR: (ResetEffector) float expected for parameter3\n";
      return boost::shared_ptr<ActionObject>(new ActionObject(GetPredicate()));
  }

  return boost::shared_ptr<ActionObject>(new ResetAction(GetPredicate(), posX, posY, angle));
}

void
ResetEffector::OnLink()
{
    SoccerBase::GetBody(*this, mBody);
    SoccerBase::GetGameState(*this, mGameState);
    SoccerBase::GetAgentState(*this, mAgentState);

    mFieldWidth = 64.0f;
    SoccerBase::GetSoccerVar(*this,"FieldWidth",mFieldWidth);

    mFieldLength = 100.0f;
    SoccerBase::GetSoccerVar(*this,"FieldLength",mFieldLength);

    mAgentRadius = 0.22f;
    SoccerBase::GetSoccerVar(*this,"AgentRadius",mAgentRadius);

    mResetNoiseXY = 0.05f;
    SoccerBase::GetSoccerVar(*this, "ResetNoiseXY",mResetNoiseXY);

    mResetNoiseAngle = 10.0f;
    SoccerBase::GetSoccerVar(*this, "ResetNoiseAngle",mResetNoiseAngle);

    UniformRngPtr rng1(new salt::UniformRNG<>(-1,1));
    mNoiseRng = rng1;
}

void
ResetEffector::OnUnlink()
{
    mBody.reset();
    mGameState.reset();
    mAgentState.reset();
    mNoiseRng.reset();
}


/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Copyright (C) 2008 RoboCup Soccer Server 3D Maintenance Group
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

#include "rewardperceptor.h"
#include <zeitgeist/logserver/logserver.h>
#include <oxygen/sceneserver/scene.h>
#include <oxygen/sceneserver/transform.h>

using namespace oxygen;
using namespace boost;
using namespace zeitgeist;
using namespace salt;
using namespace std;

RewardPerceptor::RewardPerceptor() : oxygen::Perceptor()
{
  SetPredicateName("");

  salt::Vector3f lastPos(0,0,0);
}

RewardPerceptor::~RewardPerceptor()
{
}

void RewardPerceptor::OnLink()
{
  // TODO: Do I need something here?
  //

  // Yes I want to always store the last timesteps location here
  // so as to be able to calculate the distance travelled
  // salt::Vector3f mLastPos = GetWorldTransform().pos();

}

void RewardPerceptor::OnUnlink()
{
  // TODO: Do I need something here?
  //
}

bool RewardPerceptor::Percept(boost::shared_ptr<PredicateList> predList)
{

  cout << "RewardPerceptor::Percept executed" << endl;

  // TODO: This is the juicy part
  //

  // We want positions relative to the closest parent transform node
  // Which node is this though?
  boost::shared_ptr<Transform> parent = dynamic_pointer_cast<Transform>
    (FindParentSupportingClass<Transform>().lock());

  // Get current position of agent
  salt::Vector3f myPos(0,0,0);

  if (parent.get() == 0)
  {
    GetLog()->Warning()
      << "WARNING: (RewardPerceptor) parent node is "
      << "not derived from TransformNode\n";
  }
  else
  {
    myPos = parent->GetWorldTransform().Pos();
  }


  cout << "lastPos " << lastPos << endl;


  // Calculate disposition in 3 dimensions
  salt::Vector3f distanceTravelled = myPos - lastPos;
  lastPos = myPos;


  cout << "myPos " << myPos << endl;
  cout << "distanceTravelled " << distanceTravelled << endl;
  cout << "lastPos " << lastPos << endl;

  // TODO: Choose reward
  // Which dimension is our reward dimension though?
  // Should be either length, or depth, definitely not height


  Predicate &predicate = predList->AddPredicate();
  predicate.name = mPredicateName + "R";
  predicate.parameter.Clear();

  // ParameterList &dataElement = predicate.parameter.AddList();
  // dataElement.AddValue(std::string("r"));
  // const char* data = mRender->GetData();
  // string datacode = mB64Encoder.encode(data, size);
  // dataElement.AddValue(datacode);

  return true;
}
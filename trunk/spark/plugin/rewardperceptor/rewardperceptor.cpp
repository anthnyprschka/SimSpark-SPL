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

}

void RewardPerceptor::OnUnlink()
{

}

bool RewardPerceptor::Percept(boost::shared_ptr<PredicateList> predList)
{

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


  cout << "(rewardperceptor) lastPos           " << lastPos << endl;


  // Calculate disposition in 3 dimensions
  salt::Vector3f distanceTravelled = myPos - lastPos;
  float reward = distanceTravelled[0];
  lastPos = myPos;


  cout << "(rewardperceptor) myPos             " << myPos << endl;
  cout << "(rewardperceptor) distanceTravelled " << distanceTravelled << endl;
  cout << "(rewardperceptor) reward            " << reward << endl;


  Predicate &predicate = predList->AddPredicate();
  predicate.name = mPredicateName + "R";
  predicate.parameter.Clear();

  ParameterList &dataElement = predicate.parameter.AddList();
  dataElement.AddValue(std::string("r"));
  dataElement.AddValue(reward);

  return true;
}
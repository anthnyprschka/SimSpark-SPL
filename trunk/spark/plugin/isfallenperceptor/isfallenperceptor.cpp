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
#include "isfallenperceptor.h"
#include <zeitgeist/logserver/logserver.h>
#include <oxygen/sceneserver/scene.h>
#include <oxygen/sceneserver/transform.h>
#include <iostream>

using namespace oxygen;
using namespace boost;
using namespace zeitgeist;

IsFallenPerceptor::IsFallenPerceptor() : oxygen::Perceptor()
{

  SetPredicateName("");

  bool mIsFallen = false;

  // TODO: Choose this value rationally
  float mThreshold = 0.6;

}

IsFallenPerceptor::~IsFallenPerceptor()
{
}

bool
IsFallenPerceptor::Percept(boost::shared_ptr<PredicateList> predList)
{


  cout << "IsFallenPerceptor::Percept executed" << endl;


  boost::shared_ptr<Transform> parent = dynamic_pointer_cast<Transform>
    (FindParentSupportingClass<Transform>().lock());

  // Get current position of agent
  salt::Vector3f myPos(0,0,0);

  if (parent.get() == 0)
  {
    GetLog()->Warning()
      << "WARNING: (IsFallenPerceptor) parent node is "
      << "not derived from TransformNode\n";
  }
  else
  {
    // WorldTransform should be right - we want to position
    // of the AgentAspect relative to the world, not itself.
    myPos = parent->GetWorldTransform().Pos();
  }


  cout << "IsFallenPerceptor::myPos " << myPos << endl;

  // TODO: Choose vertical dimension
  // Which dimension is our vertical dimension though?
  // Should be either length, or depth, definitely not height

  // TODO: How to address/extract a certain value from a salt::Vector3f?
  // TODO: Put in the right axis of myPos here
  // if (XXXX < mThreshold)
  // {
  //   mIsFallen = true;
  // }
  // else
  // {
  //   mIsFallen = false;
  // }

  // Predicate &predicate = predList->AddPredicate();
  // predicate.name = mPredicateName + "fallen";
  // predicate.parameter.Clear();

  // ParameterList &dataElement = predicate.parameter.AddList();
  // dataElement.AddValue(std::string("fallen"));

  // // TODO: Do I need to encode/serialize the boolean isfallen somehow?
  // dataElement.AddValue(isfallen);

  return true;
}



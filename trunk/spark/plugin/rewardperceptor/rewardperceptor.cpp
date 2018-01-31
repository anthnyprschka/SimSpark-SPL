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

using namespace oxygen;
using namespace boost;
using namespace zeitgeist;
using namespace salt;
using namespace std;

RewardPerceptor::RewardPerceptor() : oxygen::Perceptor()
{
    // TODO: Do I even need this?
    //
    SetPredicateName("");
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


  // mRender->RequestRender();

  // int size = mRender->GetDataSize();
  // if (size == 0)
  //   return false;

  Predicate &predicate = predList->AddPredicate();
  predicate.name = mPredicateName + "R";
  predicate.parameter.Clear();

  // ParameterList &sizeElement = predicate.parameter.AddList();
  // sizeElement.AddValue(std::string("s"));
  // sizeElement.AddValue(mRender->GetWidth());
  // sizeElement.AddValue(mRender->GetHeight());

  // ParameterList &dataElement = predicate.parameter.AddList();
  // dataElement.AddValue(std::string("d"));
  // const char* data = mRender->GetData();
  // string datacode = mB64Encoder.encode(data, size);
  // dataElement.AddValue(datacode);

  return true;
}
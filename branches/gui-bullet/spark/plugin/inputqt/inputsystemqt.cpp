/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Author: Patrick Geib
   Copyright (C) 2012 RoboCup Soccer Server 3D Maintenance Group
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

#include "inputsystemqt.h"
#include <kerosin/inputserver/inputserver.h>
#include <zeitgeist/logserver/logserver.h>

using namespace boost;
using namespace kerosin;
using namespace zeitgeist;

InputSystemQt::InputSystemQt() : InputSystem()
{
}

InputSystemQt::~InputSystemQt()
{
}

bool InputSystemQt::Init(InputServer *inputServer)
{
    if (InputSystem::Init(inputServer) == false)
        {
            return false;
        }

    return true;
}

bool InputSystemQt::CreateDevice(const std::string &deviceName)
{
    // InputSystemWX does not use any device classes
    return true;
}

bool InputSystemQt::UpdateTimerInput(Input& input)
{
    return true;
}

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
#ifndef RESETACTION_H
#define RESETACTION_H

#include <oxygen/gamecontrolserver/actionobject.h>
#include <salt/vector.h>

class ResetAction : public oxygen::ActionObject
{
public:
    ResetAction(const std::string& predicate, float posX, float posY, float xyangle)
        : ActionObject(predicate), mPosX(posX), mPosY(posY), mXYAngle(xyangle) {}
    virtual ~ResetAction() {}

    /** returns x coord of the position the agent wants to Reset to */
    float GetPosX() const { return mPosX; }

    /** returns x coord of the position the agent wants to Reset to */
    float GetPosY() const { return mPosY; }

    /** returns the stored angle in the x-y-plane */
    float GetXYAngle() const { return mXYAngle; }

protected:
    /** the x coord of the position to Reset the agent to */
    float mPosX;

    /** the y coord of the position to Reset the agent to */
    float mPosY;

    /** the angle in the x-y-plane at the position to Reset the agent to */
    float mXYAngle;
};

#endif // ResetACTION_H

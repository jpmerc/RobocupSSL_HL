/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module represents the field of a game. It serves to define the
 *          playable area of the game in order to know whether a ball or player
 *          is in the playable area.
 *
 ****************************************************************************/
#ifndef FIELD_H
#define FIELD_H

#include "Utils/Vector2d.h"

class Field {
public:
    Field(
        float iWidth = 0,
        float iHeight = 0,
        float iPlayableWidth = 0,
        float iPlayableHeight = 0
    );

    double getWidth() const;
    double getHeight() const;
    double getPlayableWidth() const;
    double getPlayableHeight() const;

    bool isInPlayableArea(const Vector2d &iCoordinate) const;

private:
    double mWidth;
    double mHeight;

    double mPlayableWidth;
    double mPlayableHeight;
};

#endif

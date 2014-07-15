#include "SoccerGame/Field/Field.h"


Field::Field(float iWidth, float iHeight, float iPlayableWidth, float iPlayableHeight) :
    mWidth(iWidth),
    mHeight(iHeight),
    mPlayableWidth(iPlayableWidth),
    mPlayableHeight(iPlayableHeight)
{
}

double Field::getWidth() const{
    return mWidth;
}

double Field::getHeight() const{
    return mHeight;
}

double Field::getPlayableWidth() const{
    return mPlayableWidth;
}

double Field::getPlayableHeight() const{
    return mPlayableHeight;
}

bool Field::isInPlayableArea(const Vector2d &iCoordinate) const{
    if(iCoordinate.x >= (mWidth - mPlayableWidth) / 2 &&
       iCoordinate.x <= mPlayableWidth &&
       iCoordinate.y <= mPlayableHeight &&
       iCoordinate.y >= (mHeight - mPlayableHeight) / 2
    ){
        return true;
    }

    return false;
}


#include "Utils/Orientation.h"

const Orientation Orientation::ZERO(0.0f);
//const Orientation Orientation::PI(-1.0f, 0.0f);
//const Orientation Orientation::PI_HALF();
//const Orientation Orientation::PI_QUARTER(1.0f, 1.0f);
//const Orientation Orientation::NEGATIVE_PI;
//const Orientation Orientation::NEGATIVE_PI_HALF;
//const Orientation Orientation::NEGATIVE_PI_QUARTER;

Orientation::Orientation(double iX, double iY){
    if(iX == 0 && iY == 0){
        mCartesian = Vector2d(1,0); //real zero degree
        mMagnitude = 0;
    }
    else{
        mCartesian = Vector2d(iX,iY);
        mMagnitude = mCartesian.length();
    }
    mPolar = this->_cartesianToPolar(mCartesian);
}

Orientation::Orientation(Vector2d iVector){
    if(iVector.x == 0 && iVector.y == 0){
        mCartesian = Vector2d(1,0); //real zero degree
        mMagnitude = 0;
    }
    else{
        mCartesian = iVector;
        mMagnitude = mCartesian.length();
    }
    mMagnitude = mCartesian.length();
    mPolar = this->_cartesianToPolar(mCartesian);

}


Orientation::Orientation(double iAngle):mPolar(iAngle){
    mCartesian = Vector2d(cos(mPolar),sin(mPolar));
}

void Orientation::setPolar(double iAngle){
    mPolar = iAngle;
    mCartesian = Vector2d(cos(mPolar),sin(mPolar));
}

void Orientation::setCartesian(Vector2d iCartesian){
    mCartesian = iCartesian;
    mPolar = this->_cartesianToPolar(mCartesian);
    mMagnitude = mCartesian.length();
}

void Orientation::setCartesian(double iX,double iY){
    mCartesian = Vector2d(iX,iY);
    mPolar = this->_cartesianToPolar(mCartesian);
    mMagnitude = mCartesian.length();
}

double Orientation::_cartesianToPolar(Vector2d iVector){
    if(iVector.isZero()){
        return 0.0;
    }
    else{
        return atan2(iVector.y,iVector.x);
    }
}

bool Orientation::operator==(const Orientation &other) const {
    return mCartesian == other.getCartesian() && mPolar == other.getPolar();
}

bool Orientation::operator!=(const Orientation &other) const {
    return mCartesian != other.getCartesian() || mPolar != other.getPolar();
}

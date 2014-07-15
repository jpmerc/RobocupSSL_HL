/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to interact with radians.
 *
 ****************************************************************************/
#ifndef RADIAN_H
#define RADIAN_H

//TODO: Add a degree attribute and make a converter from rad to deg

class Radian
{
public:
    Radian(float iValue = 0.0f);
    virtual ~Radian();

    float getValue(void) const;
private:
    float mValue;
};

inline float Radian::getValue(void) const{
    return mValue;
}

#endif

/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to interact with degrees.
 *
 ****************************************************************************/
#ifndef DEGREE_H
#define DEGREE_H

//TODO: Add a radian attribute and make a converter from deg to rad

class Degree
{
public:
    Degree(float iValue = 0.0f);
    virtual ~Degree();

    float getValue(void) const;
private:
    float mValue;
};

inline float Degree::getValue(void) const{
    return mValue;
}

#endif

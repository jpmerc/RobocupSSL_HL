/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module describes a ball identifier.
 *          It is used to define unique instance of a ball object.
 *
 ****************************************************************************/
#ifndef BALLID_H
#define BALLID_H

class BallId{
public:
    BallId(int iId) : mValue(iId){}

    int getValue(void) const;

    bool operator==(const BallId& other) const;
    bool operator<(const BallId& other) const; //Required when used as first value in a map

private:
    int mValue;
};

inline int BallId::getValue(void) const{
    return mValue;
}

inline bool BallId::operator==(const BallId &other) const{
    return mValue == other.mValue;
}
inline bool BallId::operator<(const BallId &other) const{
    return mValue < other.mValue;
}

#endif

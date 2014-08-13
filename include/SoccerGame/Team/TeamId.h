/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module describes a team identifier.
 *          It is used to define unique instance of a team object.
 *
 ****************************************************************************/
#ifndef TEAM_ID_H
#define TEAM_ID_H

class TeamId {
public:
    //TODO default value non valid team
    TeamId(int iId=0) : mValue(iId){}

    int getValue(void) const;

    bool operator==(const TeamId& other) const;
    bool operator<(const TeamId& other) const; //Required when used as first value in a map

private:
    int mValue;
};

inline int TeamId::getValue(void) const{
    return mValue;
}

inline bool TeamId::operator==(const TeamId &other) const{
    return mValue == other.mValue;
}

inline bool TeamId::operator<(const TeamId &other) const{
    return mValue < other.mValue;
}
#endif

/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module describes a player identifier.
 *          It is used to define unique instance of a player object in the game.
 *
 ****************************************************************************/
#ifndef PLAYER_ID_H
#define PLAYER_ID_H

class PlayerId {
public:
    //TODO default nonvalid player (-1?)
    PlayerId(int iId=0) : mValue(iId){}

    int getValue(void) const;

    bool operator==(const PlayerId& other) const;
    bool operator!=(const PlayerId& other) const;
    bool operator<(const PlayerId& other) const; //Required when used as first value in a map

private:
    int mValue;
};

inline int PlayerId::getValue(void) const{
    return mValue;
}

inline bool PlayerId::operator==(const PlayerId &other) const{
    return mValue == other.mValue;
}
inline bool PlayerId::operator !=(const PlayerId &other) const{
    return mValue != other.mValue;
}
inline bool PlayerId::operator<(const PlayerId &other) const{
    return mValue < other.mValue;
}
#endif

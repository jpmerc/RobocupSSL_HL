#include "Strategy/Play/Play.h"

#include <stdexcept>
#include <algorithm>


void Play::reset(){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        (*it)->setAssignation(false);
    }
}

Role* Play::getRole(int iId){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        if(iId == (*it)->getId()){
            return (*it);
        }
    }
    //else
    throw RoleNotFoundException("No Ids matching for getRole()");
}

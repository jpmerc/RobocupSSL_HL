#ifndef ROBOCUP_EXCEPTION_H
#define ROBOCUP_EXCEPTION_H

#include <stdexcept>
#include <string>

class RobocupException : std::runtime_error{
public:
    RobocupException(const std::string &iMessage) :
        std::runtime_error(iMessage){}
};

class PlayerNotFoundException : RobocupException{
public:
    PlayerNotFoundException(const std::string &iMessage) :
        RobocupException(iMessage){}
};

class RoleNotFoundException : RobocupException{
public:
    RoleNotFoundException(const std::string &iMessage) :
        RobocupException(iMessage){}
};



#endif

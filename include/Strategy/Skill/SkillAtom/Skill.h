#ifndef SKILL_H
#define SKILL_H

class ParameterStruct;
class CommandStruct;

class Skill
{
public:
    Skill(){}

    virtual CommandStruct operator()(ParameterStruct iParam) = 0;

private:


};

#endif // SKILL_H

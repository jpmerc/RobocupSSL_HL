#ifndef TACTIC_H
#define TACTIC_H

class Tactic
{
public:
    Tactic();

    void update();

    virtual bool isDone() = 0;
};

#endif // TACTIC_H

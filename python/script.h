#include <Python.h>

struct Vector{
    double x;
    double y;
};

struct Vector getPosition(int t);
int scriptEngine_init();

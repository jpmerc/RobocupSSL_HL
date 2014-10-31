#ifndef POC_VECTOR
#define POC_VECTOR

struct Vector{
    double x;
    double y;
    void set(double nx, double ny) {x = nx; y = ny;}
    double getX() const { return x; };
};

#endif

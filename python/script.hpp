#include <Python.h>
#include <boost/thread.hpp> 

struct Vector{
    double x;
    double y;
};

class StrategieEngine {
	int t;
	public:
		struct Vector getPosition(int t);
		StrategieEngine();
		~StrategieEngine();
};

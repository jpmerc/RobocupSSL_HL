#include <boost/thread.hpp> 
#include <boost/python.hpp>
#include "Vector.hpp"

struct Game{
	struct Vector players[2];
};

class StrategieEngine {
	int t;
	struct Game position;
	
	void updatePosition();
	private:
		boost::thread updateThread;
		PyObject* arrayToTuple(long array[]);
	public:
		StrategieEngine();
		~StrategieEngine();
		void setData(int data);
		struct Game getPosition();
};

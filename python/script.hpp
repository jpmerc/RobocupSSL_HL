#include <boost/thread.hpp> 
#include <boost/python.hpp>

struct Vector{
    double x;
    double y;
};

class StrategieEngine {
	int t;
	struct Vector position;
	
	void updatePosition();
	private:
		boost::thread updateThread;
	public:
		StrategieEngine();
		~StrategieEngine();
		void setData(int data);
		struct Vector getPosition();
};

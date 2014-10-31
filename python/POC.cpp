#include "Vector.hpp"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(POC)
{
    using namespace boost::python;

    class_<Vector>("Vector")
	    .def("set", &Vector::set)
    	    .def("getX", &Vector::getX);
}


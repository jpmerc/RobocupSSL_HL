#include "script.hpp"

StrategieEngine::StrategieEngine(){
   
    Py_Initialize();
    PyEval_InitThreads(); 
    
    //Ajouter le dossier 'scripts' au path temporaire Python
    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyUnicode_FromString("."));
    PyRun_SimpleString("import sys"); 
    PyRun_SimpleString("sys.path.insert(0, '')");

    //Relacher l'exclusivité de l'interpreteur
    //pour pouvoir l'utiliser sur les autres threads
    PyEval_ReleaseLock(); 
   
    this->updateThread = boost::thread(&StrategieEngine::updatePosition, this);//Démarrage du thread
}

StrategieEngine::~StrategieEngine(){
	this->updateThread.interrupt();
	Py_Finalize();	
}



void StrategieEngine::setData(int data){

	this->t = data;

}

void StrategieEngine::updatePosition(){
	PyGILState_STATE gstate;
	gstate = PyGILState_Ensure(); //Le thread aquérit l'interpreteur Python
		
	while(1){
		int time = this->t;
		PyObject *pName, *pModule, *pFunc;
		PyObject *pArgs, *pValue;

		struct Vector result = {0,0};

		pName = PyUnicode_FromString("position");
		/* Error checking of pName left out */

		pModule = PyImport_Import(pName);
		Py_DECREF(pName);

		if (pModule != NULL) {
			pFunc = PyObject_GetAttrString(pModule, "getPosition");
			/* pFunc is a new reference */

			if (pFunc && PyCallable_Check(pFunc)) {
			    pArgs = PyTuple_New(1);
			    pValue = PyLong_FromLong(time);
			    if (!pValue) {
				Py_DECREF(pArgs);
				Py_DECREF(pModule);
				fprintf(stderr, "Cannot convert argument\n");
			    }
			    /* pValue reference stolen here: */
			    PyTuple_SetItem(pArgs, 0, pValue);

			    pValue = PyObject_CallObject(pFunc, pArgs);
			    Py_DECREF(pArgs);
			    if (pValue != NULL) {
				result.x = PyFloat_AsDouble(PyTuple_GetItem(pValue, 0));
				result.y = PyFloat_AsDouble(PyTuple_GetItem(pValue, 1));
				//printf("Result of call: (%f,%f)\n", result.x, result.y);
				Py_DECREF(pValue);
			    }
			    else {
				Py_DECREF(pFunc);
				Py_DECREF(pModule);
				PyErr_Print();
				fprintf(stderr,"Call failed\n");
			    }
			}
			else {
			    if (PyErr_Occurred())
				PyErr_Print();
			    fprintf(stderr, "Cannot find function");
			}
		
			Py_XDECREF(pFunc);
			Py_DECREF(pModule);
		}
		else {
			PyErr_Print();
			fprintf(stderr, "Failed to load ");
		}
		
		this->position = result;

		boost::this_thread::interruption_point();

	}
	PyGILState_Release (gstate); 

}

struct Vector StrategieEngine::getPosition()
{
	return this->position;
}

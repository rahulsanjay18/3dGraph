#include </usr/include/python3.6m/Python.h>
#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;
/* 
argv[1] is the module name 
argv[2] is function name
arg[3+] the arguments
*/
PyObject * invokeFunc(int argc, char* types, string argv[])
{	
	const char * enc = "utf-8";
	const char * otherThing = "strict";
	/*for (int i = 0; i < 6; i++){
		std::cout<<argv[i]<<" ";
	}*/
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
	pValue = NULL;
    if (argc < 3) {
        fprintf(stderr,"Usage: call pythonfile funcname [args]\n");
        return pValue;
    }

    Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append(\".\")");
	
    pName = PyUnicode_DecodeFSDefault(argv[1].c_str());
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, argv[2].c_str());
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(argc - 3);
            for (i = 0; i < argc - 3; i++) {
				//std::cout<<argv[i + 3]<<"\n";
				
				switch(types[i]){
					case 'i': pValue = PyLong_FromLong(stoi(argv[i + 3])); 
						break;
					case 'b': pValue = PyBool_FromLong(stoi(argv[i + 3]));
						break;
					case 'f': pValue =  PyFloat_FromDouble(stof(argv[i + 3]));
						break;
					case 's': pValue = PyUnicode_Decode(argv[i+3].c_str(), argv[i+3].length(), enc, otherThing);
						break;
					default: pValue = 0;
				}
				
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return pValue;
                }
				
				
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %ld\n", PyLong_AsLong(pValue));
               	return pValue;
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return pValue;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2].c_str());
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1].c_str());
        return pValue;
    }
    if (Py_FinalizeEx() < 0) {
        return pValue;
    }
    return pValue;
}
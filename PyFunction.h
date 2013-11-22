/* 
 * File:   PyFunction.h
 * Author: Kent D. Lee
 * (c) 2013
 * Created on February 15, 2013, 10:05 PM
 * 
 * License:
 * Please read the LICENSE file in this distribution for details regarding
 * the licensing of this code. This code is freely available for educational
 * use. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
 * 
 * Description:
 * One PyFunction object is created by the parser for each function found
 * in the casm input file. In addition, when a nested function appears in 
 * a casm file, there is a PyFunction object created before the outer function
 * calls the inner function. If variables in the outer function are referenced
 * by the inner function, a closure is created which is also a PyFunction 
 * object. Read more about closures in the text. 
 */

#ifndef PYFUNCTION_H
#define	PYFUNCTION_H

#include "PyCallable.h"
#include "PyCode.h"
#include "PyCell.h"
#include "PyTuple.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class PyFunction : public PyCallable {
public:
    PyFunction(PyCode& code, map<string,PyObject*>& globals, PyObject* closure);
    virtual ~PyFunction();
    PyType* getType();
    
    PyObject* __call__(vector<PyObject*>* args);
    bool allowableArgCount(int count);
    string toString();
    string callName();
    
    
private:
    PyCode& code;
    map<string,PyObject*>& globals;
    map<string,PyCell*> cellvars;
};

#endif	/* PYFUNCTION_H */

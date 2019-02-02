#include "Model.h"
#include "Functions.h"

#include <functional>
#include <Urho3D/Math/Vector3.h>

using namespace Urho3D;
using namespace MVC;

Model* Model::instance;

std::function<Vector3(float,float,float)> Model::getFunction(){
    return graphFunction;
}

///Note: not a class member function
Vector3 Custom(float u, float v, float t){
    std::string funcStr = Model::getInstance()->getCurrentCustom();
    // Do python magic right here
    //Assign python function call return value to python object variable
    //Parse the variable as an array of size 3
    //return vector with the 3 array elements
    return Vector3(u, v, t);
}

void Model::initInstance(){
    instance = new Model();
    instance->functionMap["Sine"] = Sine;
    instance->functionMap["MultiSine"] = MultiSine;
    instance->functionMap["Sine2D"] = Sine2D;
    instance->functionMap["MultiSine2DFunction"] = MultiSine2DFunction;
    instance->functionMap["Ripple"] = Ripple;
    instance->functionMap["Cylinder"] = Cylinder;
    instance->functionMap["Sphere"] = Sphere;
    instance->functionMap["Torus"] = Torus;
    instance->functionMap["Custom"] = Custom;
}

Model* Model::getInstance(){
    return instance;
}

void Model::deleteInstance(){
    delete instance;
}


bool Model::setFunction(std::string key){
    if (functionMap.count(key)==1){
        graphFunction = functionMap[key];
        return true;
    }
    else return false;
}

void Model::setCurrentCustom(std::string funcStr){
    currentCustom = funcStr;
}

std::string Model::getCurrentCustom(){
    return currentCustom;
}

/*
///Most dangerous thing on this folder
///Test carefully
std::string* Model::getFunctionList(){
    int elements = functionMap.size();
    std::string* functionList = new std::string[elements];
    int index = 0;
    for (auto& x : functionMap){
        functionList[index] = x.first;
        ++index;
    }
    return functionList;
}*/

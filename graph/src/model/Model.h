#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "Functions.h"

#include <functional>
#include <Urho3D/Math/Vector3.h>
#include <map>

namespace MVC{
class Model{
private:
    std::string currentCustom;
    std::function<Vector3(float, float, float)> graphFunction;
    std::map<std::string, std::function<Vector3(float, float, float)>> functionMap;
    static Model* instance;
    //Function pointer
    //custom function map or list
public:
    std::function<Vector3(float,float,float)> getFunction();
    static Model* getInstance();
    static void initInstance();
    static void deleteInstance();
    bool setFunction(std::string);
    void setCurrentCustom(std::string);
    std::string getCurrentCustom();
};
}
#endif

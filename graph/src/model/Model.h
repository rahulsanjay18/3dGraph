#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "Functions.h"

#include <functional>
#include <Urho3D/Math/Vector3.h>
#include <map>

namespace MVC{
class Model{
private:
    std::string currentCustom;                                                          ///Custom function string
    std::function<Vector3(float, float, float)> graphFunction;                          ///Current private function variable
    std::map<std::string, std::function<Vector3(float, float, float)>> functionMap;     ///Dictionary with string keys and function values
    static Model* instance;                                                             ///Singleton instance
    //Function pointer
    //custom function map or list
public:
    std::function<Vector3(float,float,float)> getFunction();  ///return the current function
    static Model* getInstance();                              ///return the singleton instance
    static void initInstance();                               ///initialize instance
    static void deleteInstance();                             ///Delete singleton instance
    bool setFunction(std::string);                            ///Set the current function based on the function value of the string key
    void setCurrentCustom(std::string);                       ///Set custom string function
    std::string getCurrentCustom();                           ///Return the custom string function
};
}
#endif

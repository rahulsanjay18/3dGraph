#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <sstream>
#include <Urho3D/Math/Vector3.h>
#include <map>
#include <string>
#include <functional>

using namespace Urho3D;

//static const int res = 100;
//These don't work for function pointer
Vector3 Quadratic(float);
Vector3 Linear(float);
Vector3 Sin(float, float, float, float);
//These work for function pointer
Vector3 Sine(float, float, float);
Vector3 MultiSine(float, float, float);
Vector3 Sine2D(float, float, float);
Vector3 MultiSine2DFunction(float, float, float);
Vector3 Ripple(float, float, float);
Vector3 Cylinder(float, float, float);
Vector3 Sphere(float, float, float);
Vector3 Torus(float, float, float);

#endif

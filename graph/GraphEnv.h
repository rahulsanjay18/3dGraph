#ifndef GRAPHENV_H_INCLUDED
#define GRAPHENV_H_INCLUDED

#include "Functions.h"
#include <functional>
#include <Urho3D/Math/Vector3.h>

class GraphEnv {
private:
  string custom;
  function<Vector3(float, float, float)> graphFunction;
  static const int SIDE_LENGTH = 50
  double xMax, yMax, xMin, yMin;
  static GraphEnv* instance;
  // Set defaults
  xMax = 25;
  yMax = 25;
  xMin = -25;
  yMin = -25;
public:
  static GraphEnv* getInstance();
  static initInstance();
  static deleteInstance();
  function getFunction();
  double getXMax();
  double getYMax();
  double getXMin();
  double getYMin();
};

#endif

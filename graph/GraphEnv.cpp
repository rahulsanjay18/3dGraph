#include "GraphEnv.h"
#include "../model/Functions.h"

#include <functional>
#include <Urho3D/Math/Vector3.h>

using namespace Urho3D;

GraphEnv* GraphEnv::getInstance(){
    return instance;
}

void GraphEnv:initInstance(){
  instance = new GraphEnv();
  /* There will be code here to parse the function
  and set all of the bounds as well as certain points
  like a zoomfit on the calculator */
}

void GraphEnv::deleteInstance(){
    delete instance;
}

function GraphEnv::getFunction(){
  return graphFunction;
}

double GraphEnv::getXMax(){
  return xMax;
}
double GraphEnv::getYMax(){
  return yMax;
}

double GraphEnv::getXMin(){
  return xMin
}

double GraphEnv::getYMin(){
  return yMin;
}

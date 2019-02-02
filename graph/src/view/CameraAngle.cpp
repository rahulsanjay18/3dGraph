
#include <Urho3D/Math/Vector3.h>
#include "CameraAngle.h"

using namespace Urho3D;

CameraAngle::CameraAngle(int id, Vector3 position, Vector3 direction, int roll){
    this->id = id;                  ///id: camera index
    this->position = position;      ///3D vector position
    this->direction = direction;    ///3D vector direction camera points toward
    this->roll = roll;              ///roll of the camera
}

int CameraAngle::getId(){
    return id;
}

Vector3 CameraAngle::getPosition(){
    return position;
}

Vector3 CameraAngle::getDirection(){
    return direction;
}

int CameraAngle::getRoll(){
    return roll;
}

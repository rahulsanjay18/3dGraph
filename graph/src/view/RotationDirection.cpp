#include "RotationDirection.h"

RotationDirection::RotationDirection(std::string identification, int q){
    quaternion_bits = q;
    id = identification;
}

RotationDirection::~RotationDirection(){
    //Properly delete this
    delete quaternions;
}

int RotationDirection::getBits(){
    return quaternion_bits;
}

std::string RotationDirection::getId(){
    return this->id;
}

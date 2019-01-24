#include "RotationDirection.h"

RotationDirection::RotationDirection(std::string identification, int q[4][3]){
    quaternions = q;
    id = identification;
}

RotationDirection::~RotationDirection(){
    //Properly delete this
    delete quaternions;
}

int RotationDirection::getElement(int r, int c){
    return quaternions[r][c];
}

std::string RotationDirection::getId(){
    return this->id;
}

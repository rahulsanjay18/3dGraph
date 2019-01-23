#include "RotationDirection.h"

RotationDirection::RotationDirection(std::string identification, int[4][3] q){
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

std::string RotationDirectiongetId(){
    return id;
}

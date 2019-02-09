#include "RotationDirection.h"

RotationDirection::RotationDirection(std::string identification, int q){
    //quaternion_bits = q;
    quaternions = new int*[4];
    for (int i = 0; i < 4; i++){
        int subBits = q >> ((3 - i) * 6);
        quaternions[i] = new int[3];
        for (int j = 0; j < 3; j++){
            int value = (subBits >> ((2 - j) * 2)) & 3;
            quaternions[i][j] = value == 3 ? -1 : value;
        }
    }
    id = identification;
}

RotationDirection::~RotationDirection(){
    //Properly delete this
    delete quaternions;
}

int* RotationDirection::getCameraVals(int index){
    return quaternions[index];
}

std::string RotationDirection::getId(){
    return this->id;
}

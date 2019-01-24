#ifndef ROTATIONDIRECTION_H_INCLUDED
#define ROTATIONDIRECTION_H_INCLUDED

#include <string>

class RotationDirection{
private:
    //int quaternion_bits;
    int** quaternions;
    std::string id;
public:
    RotationDirection(std::string id, int);
    ~RotationDirection();
    int* getCameraVals(int);
    std::string getId();
};
#endif // ROTATIONDIRECTION_H_INCLUDED

#ifndef ROTATIONDIRECTION_H_INCLUDED
#define ROTATIONDIRECTION_H_INCLUDED

#include <string>

class RotationDirection{
private:
    int** quaternions;
    std::string id;
public:
    RotationDirection(std::string id, int[4][3]);
    ~RotationDirection();
    int getElement(int, int);
    std::string getId();
};
#endif // ROTATIONDIRECTION_H_INCLUDED

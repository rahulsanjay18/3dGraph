#ifndef CAMERAANGLE_H_INCLUDED
#define CAMERAANGLE_H_INCLUDED

#include <Urho3D/Graphics/Graphics.h>

class CameraAngle{
	private:
		int id;
		Urho3D::Vector3 position;
		Urho3D::Vector3 direction;
		int roll;
	public:
		CameraAngle(int, Urho3D::Vector3, Urho3D::Vector3, int);
		int getId();
		Urho3D::Vector3 getPosition();
		Urho3D::Vector3 getDirection();
		int getRoll();
};

#endif // CAMERAANGLE_H_INCLUDED

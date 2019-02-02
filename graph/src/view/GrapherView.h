#ifndef GRAPHERVIEW_H_INCLUDED
#define GRAPHERVIEW_H_INCLUDED

#include "AbstractView.h"
#include "CameraAngle.h"
#include "CameraObject.h"
#include "RotationDirection.h"
#include <Urho3D/Math/Rect.h>
#include <Urho3D/Math/Vector3.h>

class GrapherView : public AbstractView{
	private:
		CameraAngle* cameraAngles[4];           ///Contains camera angles and objects
		CameraObject* cameraObjects[4];
		IntRect* rect[4];                       ///Rectangular frames for view ports
		Node* lightNode;                        ///Determines lighting for environment
		void setUpCameraAngles();               ///Set ups for rectangular frames and camera angles
		void setUpViewRects();
		//void setUpCamera(int);
		//void setUpViewPort(int);
		void setUpLighting();                   ///Set up lighting
		//void setUpBackground();
	protected:
		//virtual void handleInputs();
		void setUpDisplay();                    ///Initializes elements needed for display
	public:
		GrapherView(Urho3D::Renderer*, Urho3D::Scene*);
		void rotation(RotationDirection);
		void zoom(Vector3, float);
		~GrapherView();
		void display();
};

#endif //GRAPHERVIEW_H_INCLUDED

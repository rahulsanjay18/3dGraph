#ifndef GRAPHERVIEW_H_INCLUDED
#define GRAPHERVIEW_H_INCLUDED

#include "AbstractView.h"
#include "CameraAngle.h"
#include "CameraObject.h"
#include <Urho3D/Math/Rect.h>

class GrapherView : public AbstractView{
	private:
		CameraAngle* cameraAngles[4];
		CameraObject* cameraObjects[4];
		IntRect* rect[4];
		Node* lightNode;
		void setUpCameraAngles();
		void setUpViewRects();
		//void setUpCamera(int);
		//void setUpViewPort(int);
		void setUpLighting();
		//void setUpBackground();
	protected:
		//virtual void handleInputs();
		void setUpDisplay();
	public:
		GrapherView(Urho3D::Renderer*, Urho3D::Scene*);
		~GrapherView();
		void display();
};

#endif //GRAPHERVIEW_H_INCLUDED

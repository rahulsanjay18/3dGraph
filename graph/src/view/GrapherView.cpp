#include "GrapherView.h"
#include "AbstractView.h"
#include "RotationDirection.h"
#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Math/Vector3.h>
#include <iostream> //todo: delete later

using namespace Urho3D;

/**
 *
 */
GrapherView::GrapherView(Urho3D::Renderer* renderer, Urho3D::Scene* scene) :
AbstractView(renderer, scene)
{
}

void GrapherView::setUpCameraAngles(){
	cameraAngles[0] = new CameraAngle(0, Vector3(0,0,-2), Vector3::FORWARD, 0);
	cameraAngles[1] = new CameraAngle(1, Vector3(-3,0,0), Vector3::RIGHT, 90);
	cameraAngles[2] = new CameraAngle(2, Vector3(0,0,2), Vector3::BACK, 180);
	cameraAngles[3] = new CameraAngle(3, Vector3(3,0,0), Vector3::LEFT, 270);
}

void GrapherView::setUpViewRects(){
	rect[0] = new IntRect(400, 400, 800, 700);
	rect[1] = new IntRect(100,150,400,550);
	rect[2] = new IntRect(400, 0, 800, 300);
	rect[3] = new IntRect(800, 150, 1100, 550);
}

/**
 *
 */
void GrapherView::setUpLighting(){
	lightNode = this->getScene()->CreateChild();
	lightNode->SetDirection(Vector3::FORWARD);
	lightNode->Yaw(50);     // horizontal
	lightNode->Pitch(10);   // vertical
	Light* light = lightNode->CreateComponent<Light>();
	light->SetLightType(LIGHT_DIRECTIONAL);
	light->SetBrightness(1.6);
	light->SetColor(Color(1.0, .6, 0.3, 1));
	light->SetCastShadows(true);
}

/**
 *
 */
void GrapherView::setUpDisplay(){
    CameraObject::setRenderer(getRenderer());
    CameraObject::setScene(getScene());
	setUpCameraAngles();
	setUpViewRects();
	for (int i = 0; i < 4; i++){
		cameraObjects[i] = new CameraObject(rect[i], cameraAngles[i]);
		cameraObjects[i]->initialize();
		//Current issue is here ^ at CameraObject::initialize()
	}
}

/**
 *
 */
void GrapherView::display(){
	//handleInputs();
	setUpLighting();
	setUpDisplay();
};

GrapherView::~GrapherView(){
	//Handle potential memory leaks here
	delete[] cameraAngles;
	delete[] cameraObjects;
	delete[] rect;
	//delete lightNode;
}

void GrapherView::rotation(RotationDirection direction){
    for (int i = 0; i < 4; i++){
        int *values = direction.getCameraVals(i);
        cameraObjects[i]->rotation(*(values),
                                   *(values + 1),
                                   *(values + 2),i);
    }
}

void GrapherView::zoom(Vector3 direction, float factor){
    for (int i = 0; i < 4; i++){
        cameraObjects[i]->zoom(direction, factor, i);
    }
}

#include "CameraObject.h"
#include <Urho3D/Scene/Scene.h>

using namespace Urho3D;

Scene* CameraObject::scene_;

CameraObject::CameraObject(IntRect* rect, CameraAngle* angle){
    this->rect = rect;
    cameraAngle = angle;
}

void CameraObject::setRenderer(Renderer* renderer){
    renderer = renderer;
}

void CameraObject::setScene(Scene* scene){
    scene_ = scene;
}

void CameraObject::setUpCamera(){
	cameraNode = CameraObject::scene_->CreateChild("Camera");
	camera = cameraNode->CreateComponent<Camera>();
	camera->SetFarClip(2000);
	cameraNode->Translate(cameraAngle->getPosition());
	cameraNode->SetDirection(cameraAngle->getDirection());
	cameraNode->Roll(cameraAngle->getRoll());
}

void CameraObject::setUpViewPort(){
    //Potential issue
	viewport = new Viewport(CameraObject::scene_->GetContext(), scene_, cameraNode->GetComponent<Camera>(), *rect);
	renderer->SetViewport(cameraAngle->getId(), viewport);
}

void CameraObject::initialize(){
    setUpCamera();
    setUpViewPort();
}

CameraObject::~CameraObject(){
    delete viewport;
}

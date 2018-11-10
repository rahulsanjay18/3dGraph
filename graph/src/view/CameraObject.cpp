#include "CameraObject.h"
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Renderer.h>
#include <iostream>

using namespace Urho3D;

Scene* CameraObject::scene_;
Renderer* CameraObject::renderer;

CameraObject::CameraObject(IntRect* rect, CameraAngle* angle){
    this->rect = rect;
    cameraAngle = angle;
}

void CameraObject::setRenderer(Renderer* r){
    renderer = r;
}

void CameraObject::setScene(Scene* scene){
    CameraObject::scene_ = scene;
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
	viewport = new Viewport(CameraObject::scene_->GetContext(), CameraObject::scene_, cameraNode->GetComponent<Camera>(), *rect);
	//Segmentation fault here
	renderer->SetViewport(cameraAngle->getId(), viewport);
}

void CameraObject::initialize(){
    setUpCamera();
    setUpViewPort();
}

CameraObject::~CameraObject(){
    delete viewport;
}

#include "CameraObject.h"

using namespace Urho3D;

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
	cameraNode = scene_->CreateChild("Camera");
	camera = cameraNode->CreateComponent<Camera>();
	camera->SetFarClip(2000);
	cameraNode->Translate(cameraAngle->getPosition());
	cameraNode->SetDirection(cameraAngle->getDirection());
	cameraNode->Roll(cameraAngle->getRoll());
}

void CameraObject::setUpViewPort(){
    //Potential issue
	viewport = new Viewport(scene_->GetContext(), scene_, cameraNode->GetComponent<Camera>(), *rect);
	renderer->SetViewport(cameraAngle->getId(), viewport);
}

void CameraObject::initialize(){
    setUpCamera();
    setUpViewPort();
}

CameraObject::~CameraObject(){
    delete viewport;
}

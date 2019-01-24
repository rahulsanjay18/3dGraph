#include "CameraObject.h"
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Math/Vector3.h>

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
	renderer->SetViewport(cameraAngle->getId(), viewport);
}

void CameraObject::initialize(){
    setUpCamera();
    setUpViewPort();
}

CameraObject::~CameraObject(){
    delete viewport;
}

void CameraObject::rotation(int x, int y, int z, int id){
    cameraNode->SetPosition(-(Quaternion(x,y,z) * -cameraNode->GetWorldPosition()));
    cameraNode->LookAt(Vector3(0,0,0));
    if (id != 0){
        cameraNodes->Roll(id * 90);
    }
}

void CameraObject::zoom(Vector3 v, float factor, int id){
    cameraNode->Translate(v*factor);
    cameraNode->LookAt(Vector3(0,0,0));
    if (id != 0){
        cameraNodes->Roll(id * 90);
    }
}

#ifndef CAMERAOBJECT_H_INCLUDED
#define CAMERAOBJECT_H_INCLUDED

#include "CameraAngle.h"
#include <Urho3D/Math/Rect.h>
#include <Urho3D/Container/Ptr.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Viewport.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Math/Rect.h>
#include <Urho3D/Container/Ptr.h>

using namespace Urho3D;

class CameraObject{
    private:
        CameraAngle* cameraAngle;
		SharedPtr<Node> cameraNode;
		Camera* camera;
		SharedPtr<Viewport> viewport;
		IntRect* rect;
		static Renderer* renderer;
		static Scene* scene_;
        void setUpCamera();
        void setUpViewPort();
    public:
        static void setRenderer(Renderer*);
        static void setScene(Scene*);
        CameraObject();
        ~CameraObject();
        CameraObject(IntRect*, CameraAngle*);
        void initialize();
};
#endif // CAMERAOBJECT_H_INCLUDED

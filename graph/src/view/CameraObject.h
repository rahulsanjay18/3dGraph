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
#include <Urho3D/Math/Vector3.h>

using namespace Urho3D;

class CameraObject{
    private:
        CameraAngle* cameraAngle;       ///Contains values for the camera angle
		SharedPtr<Node> cameraNode;     ///Node to a camera
		Camera* camera;                 ///Camera itself
		SharedPtr<Viewport> viewport;   ///Viewport which to send the images to
		IntRect* rect;                  ///Rectangular frame object
		static Renderer* renderer;      ///Renderer
		static Scene* scene_;           ///Scene
        void setUpCamera();             ///Set up functions for camera and viewport
        void setUpViewPort();
    public:
        static void setRenderer(Renderer*);
        static void setScene(Scene*);
        CameraObject();
        ~CameraObject();
        CameraObject(IntRect*, CameraAngle*);
        void initialize();
        void rotation(int, int, int, int);
        void zoom(Vector3, float, int);
};
#endif // CAMERAOBJECT_H_INCLUDED

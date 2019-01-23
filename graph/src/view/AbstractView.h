#ifndef ABSTRACTVIEW_H_INCLUDED
#define ABSTRACTVIEW_H_INCLUDED
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Math/Vector3.h>
#include "RotationDirection.h"

/**
 * Abstract class for user interface
 *
 */
class AbstractView{
	private:
	    Urho3D::Renderer* renderer;
	    Urho3D::Scene* scene;
	protected:
		//virtual void handleInputs() =0;
		virtual void setUpDisplay() =0;
		AbstractView(Urho3D::Renderer*, Urho3D::Scene*);
	public:
	    Urho3D::Scene* getScene();
	    Urho3D::Renderer* getRenderer();
	    void setRenderer(Urho3D::Renderer*);
	    //virtual View getInstance() =0;
		virtual void display() =0;
		virtual void rotation(RotationDirection) =0;
		virtual void zoom(Vector3, float) =0;
		//There may be more functions to add for view;
};

#endif

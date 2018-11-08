#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Scene/Scene.h>

/**
 * Abstract class for user interface
 *
 */
class AbstractView{
	private:
	    Urho3D::Renderer* renderer;
	    Urho3D::Scene* scene;
	protected:
		virtual void handleInputs() =0;
		virtual void setUpDisplay() =0;
		AbstractView(Urho3D::Renderer*, Urho3D::Context*);
	public:
	    Urho3D::Scene* getScene();
	    Urho3D::Renderer* getRenderer();
	    void setRenderer(Urho3D::Renderer*);
	    //virtual View getInstance() =0;
		virtual void display() =0;
		//There may be more functions to add for view;
};

#endif

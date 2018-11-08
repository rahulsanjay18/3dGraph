#include "AbstractView.h"
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Core/Context.h>

AbstractView::AbstractView(Urho3D::Renderer* renderer, Urho3D::Context* context){
    this->renderer = renderer;
    this->scene = new Urho3D::Scene(context);
}

Urho3D::Renderer* AbstractView::getRenderer(){
    return renderer;
}

#include "AbstractView.h"
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Scene/Scene.h>

AbstractView::AbstractView(Urho3D::Renderer* renderer, Urho3D::Scene* scene){
    this->renderer = renderer;
    this->scene = scene;
}

Urho3D::Renderer* AbstractView::getRenderer(){
    return renderer;
}

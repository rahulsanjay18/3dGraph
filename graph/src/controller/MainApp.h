#include <string>
#include <sstream>

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/UIEvents.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Geometry.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/DebugRenderer.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/StaticModelGroup.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Skybox.h>
#include "GraphGenerator.h"

#include "../view/

using namespace Urho3D;

class MyApp : public Application
{
public:
	int framecount_;
	float time_=0;
	SharedPtr<Text> text_;
	SharedPtr<Scene> scene_;
    SharedPtr<Node> boxNode_;
	static const int res = 100;
	Node* lines[res];
	StaticModel* objects[res];
	Node* grid[res*res];
	StaticModel* surface[res*res];
	SharedPtr<Node> cameraNode_;
	ResourceCache* cache;
	SharedPtr<Viewport> viewport[4];
	SharedPtr<Node> cameraNodes[4];
	Camera* cameras[4];
	SharedPtr<Viewport> viewports[4];
	Renderer* renderer;
	Renderer* renderers[4];

    MyApp(Context * context) : Application(context),framecount_(0),time_(0)
    {
    }

    virtual void Setup()
    {
		view = new GrapherView();
		/*
        engineParameters_["FullScreen"]=false;
        engineParameters_["WindowWidth"]=1280;
        engineParameters_["WindowHeight"]=720;
        engineParameters_["WindowResizable"]=true;
		*/
    }

	virtual void Start()
	{
		cache = GetSubsystem<ResourceCache>();

		// Let's use the default style that comes with Urho3D.
		GetSubsystem<UI>()->GetRoot()->SetDefaultStyle(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));

		scene_ = new Scene(context_);
		// Let the scene have an Octree component!
		scene_->CreateComponent<Octree>();
		// Let's add an additional scene component for fun.
		scene_->CreateComponent<DebugRenderer>();
		//Create the sky background
		//Find out how to change the background
		Node* skyNode = scene_->CreateChild("Sky");
		skyNode->SetScale(500.0f); //The scale does not matter
		Skybox* skybox = skyNode->CreateComponent<Skybox>();
		skybox->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
		skybox->SetMaterial(cache->GetResource<Material>("Materials/Skybox.xml"));

		// More view code
		/*
		StaticModelGroup* group = new StaticModelGroup(context_);
		for (int i = 0; i < res*res; i++)
		{
			float step = 2.0f / res;
			grid[i] = scene_->CreateChild("Box");
			grid[i]->SetPosition(Vector3(0, 0, 0));
			grid[i]->SetScale(Vector3(step, step, step));
			surface[i] = grid[i]->CreateComponent<StaticModel>();
			surface[i]->SetModel(cache->GetResource<Model>("Models/Box.mdl"));
			surface[i]->SetMaterial(cache->GetResource<Material>("Materials/Stone.xml"));
			surface[i]->SetCastShadows(false);
			group->AddInstanceNode(grid[i]);
		}
		*/
		/*
		// We need a camera from which the viewport can render.
		cameraNode_ = scene_->CreateChild("Camera");
		Camera* camera = cameraNode_->CreateComponent<Camera>();
		camera->SetFarClip(2000);

		for (int i = 0; i < 4; i++) {
			cameraNodes[i] = scene_->CreateChild("Camera");
			cameras[i] = cameraNodes[i]->CreateComponent<Camera>();
			camera->SetFarClip(2000);
		}

		cameraNodes[0]->Translate(Vector3(0, 0, -2));
		cameraNodes[1]->Translate(Vector3(-3, 0, 0));
		cameraNodes[2]->Translate(Vector3(0, 0, 2));
		cameraNodes[3]->Translate(Vector3(3, 0, 0));
		cameraNodes[0]->SetDirection(Vector3::FORWARD);
		cameraNodes[1]->SetDirection(Vector3::RIGHT);
		cameraNodes[2]->SetDirection(Vector3::BACK);
		cameraNodes[3]->SetDirection(Vector3::LEFT);
		cameraNodes[1]->Roll(90);
		cameraNodes[2]->Roll(180);
		cameraNodes[3]->Roll(270);

		renderer = GetSubsystem<Renderer>();
		/*Layout of everything(camera, viewports, etc.)
			2
		1		3
			0
		*//*
		IntRect rect0(400, 400, 800, 700);
		IntRect rect1(100,150,400,550);
		IntRect rect2(400, 0, 800, 300);
		IntRect rect3(800, 150, 1100, 550);
		viewports[0] = new Viewport(context_, scene_, cameraNodes[0]->GetComponent<Camera>(), rect0);
		viewports[1] = new Viewport(context_, scene_, cameraNodes[1]->GetComponent<Camera>(), rect1);
		viewports[2] = new Viewport(context_, scene_, cameraNodes[2]->GetComponent<Camera>(), rect2);
		viewports[3] = new Viewport(context_, scene_, cameraNodes[3]->GetComponent<Camera>(), rect3);
		renderer->SetViewport(0, viewports[0]);
		renderer->SetViewport(1, viewports[1]);
		renderer->SetViewport(2, viewports[2]);
		renderer->SetViewport(3, viewports[3]);*/
		/*
		{
			Node* lightNode = scene_->CreateChild();
			lightNode->SetDirection(Vector3::FORWARD);
			lightNode->Yaw(50);     // horizontal
			lightNode->Pitch(10);   // vertical
			Light* light = lightNode->CreateComponent<Light>();
			light->SetLightType(LIGHT_DIRECTIONAL);
			light->SetBrightness(1.6);
			light->SetColor(Color(1.0, .6, 0.3, 1));
			light->SetCastShadows(true);
		}*/

		//controller code
		float step = 2.0f / res;
		float t = time_;
		for (int z = 0, i = 0; z < res; z++)
		{
			float v = (z + 0.5f) * step - 1.0f;
			for (int x = 0; x < res; x++, i++)
			{
				float u = (x + 0.5f) * step - 1.0f;
				grid[i]->SetPosition(Torus(u, v, t));
			}
		}
		//controller
		SubscribeToEvent(E_BEGINFRAME, URHO3D_HANDLER(MyApp, HandleBeginFrame));
		SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(MyApp, HandleKeyDown));
		SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(MyApp, HandleUpdate));
		SubscribeToEvent(E_POSTUPDATE, URHO3D_HANDLER(MyApp, HandlePostUpdate));
		SubscribeToEvent(E_RENDERUPDATE, URHO3D_HANDLER(MyApp, HandleRenderUpdate));
		SubscribeToEvent(E_POSTRENDERUPDATE, URHO3D_HANDLER(MyApp, HandlePostRenderUpdate));
		SubscribeToEvent(E_ENDFRAME, URHO3D_HANDLER(MyApp, HandleEndFrame));
    }

    virtual void Stop()
    {
    }

    /**
    * Every frame's life must begin somewhere. Here it is.
    */
    void HandleBeginFrame(StringHash eventType,VariantMap& eventData)
    {
        // We really don't have anything useful to do here for this example.
        // Probably shouldn't be subscribing to events we don't care about.
    }

    /**
    * Input from keyboard is handled here. I'm assuming that Input, if
    * available, will be handled before E_UPDATE.
    */
    void HandleKeyDown(StringHash eventType,VariantMap& eventData)
    {
		using namespace KeyDown;
		int key = eventData[P_KEY].GetInt();
		if (key == KEY_ESCAPE)
			engine_->Exit();

		if (key == KEY_TAB)    // toggle mouse cursor when pressing tab
		{
			GetSubsystem<Input>()->SetMouseVisible(!GetSubsystem<Input>()->IsMouseVisible());
			GetSubsystem<Input>()->SetMouseGrabbed(!GetSubsystem<Input>()->IsMouseGrabbed());
		}
    }
	//Controller code
	void HandleClosePressed(StringHash eventType,VariantMap& eventData);
	void HandleUpdate(StringHash eventType,VariantMap& eventData);
	void HandlePostUpdate(StringHash eventType,VariantMap& eventData);
	void HandleRenderUpdate(StringHash eventType, VariantMap & eventData);
	void HandlePostRenderUpdate(StringHash eventType, VariantMap & eventData);
	void HandleEndFrame(StringHash eventType,VariantMap& eventData);
};

//Not sure if this goes here or in MainApp.cpp
//URHO3D_DEFINE_APPLICATION_MAIN(MyApp)

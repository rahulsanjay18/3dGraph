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


#include "../model/Functions.h"
#include "../view/CameraAngle.h"
#include "../view/CameraObject.h"
#include "../view/AbstractView.h"
#include "../view/GrapherView.h"
#include "../model/Model.h"
#include "GraphGenerator.h"

using namespace Urho3D;

class Controller : public Application
{
public:
    AbstractView* view;             //The View object from the MVC architecture; Handles the 4 cameras and renderers
    int framecount_;
    float time_=0;                  //Time variable
    //SharedPtr<Text> text_;
    Scene* scene_;                  //The object that stores the background scene of the program's environment
    //SharedPtr<Node> boxNode_;
	static const int res = 100;     //the number of cubes on one side of the square domain D
	Node* grid[res*res];            //The grid of points to use to graph the 3D image on the center
	StaticModel* surface[res*res];  //the object storing the surface of each cube
	ResourceCache* cache;           //Cache object
	Renderer* renderer;             //Object for rendering the image through the view

    Controller(Context * context) : Application(context),framecount_(0),time_(0)
    {
    }

    /**
     *  Subscribes all functions regarding the updating of the
     *  application and rendering, frame beginning and ending,
     *  and mouse and keyboard inputs
     */
    void SubscribeEvents(){
        SubscribeToEvent(E_BEGINFRAME, URHO3D_HANDLER(Controller, HandleBeginFrame));
		SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(Controller, HandleKeyDown));
		SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(Controller, HandleUpdate));
		SubscribeToEvent(E_POSTUPDATE, URHO3D_HANDLER(Controller, HandlePostUpdate));
		SubscribeToEvent(E_RENDERUPDATE, URHO3D_HANDLER(Controller, HandleRenderUpdate));
		SubscribeToEvent(E_POSTRENDERUPDATE, URHO3D_HANDLER(Controller, HandlePostRenderUpdate));
		SubscribeToEvent(E_ENDFRAME, URHO3D_HANDLER(Controller, HandleEndFrame));
    }

    /**
     * Setup function runs before the Start function
     * Sets up window settings; window size 1280 x 720 pixels
     *
     */
    virtual void Setup()
    {
        engineParameters_["FullScreen"]=false;
        engineParameters_["WindowWidth"]=1280;
        engineParameters_["WindowHeight"]=720;
        engineParameters_["WindowResizable"]=true;
    }

    /**
     * Start initializes every object needed such as the view and model object,
     * and also the cubes used to graph the 3D functions
     *
     */
	virtual void Start()
	{
        renderer = GetSubsystem<Renderer>();
		cache = GetSubsystem<ResourceCache>();
		// Let's use the default style that comes with Urho3D.
		GetSubsystem<UI>()->GetRoot()->SetDefaultStyle(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
		// Let the scene have an Octree component!
		scene_ = new Scene(context_);
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

		// Init grid for surfaces
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

		///Initialize the 4 cameras and renderers
		view = new GrapherView(renderer, scene_);
		view->display();

        ///Initialize the singleton model object
        MVC::Model::initInstance();

        ///give coordinates to each cube using a 3d function from the model function
		float step = 2.0f / res;
		float t = time_;
		for (int z = 0, i = 0; z < res; z++)
		{
			float v = (z + 0.5f) * step - 1.0f;
			for (int x = 0; x < res; x++, i++)
			{
				float u = (x + 0.5f) * step - 1.0f;
				grid[i]->SetPosition(MVC::Model::getInstance()->getFunction()(u, v, t));
			}
		}
        SubscribeEvents();
    }

    /**
     * Add things to do before halting the program when user closes it.
     */
    virtual void Stop()
    {
		//Avoid memory leaks by explicitly deleting pointers
		MVC::Model::deleteInstance();
		delete view;
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

    /**
    * You can get these events from when ever the user interacts with the UI.
    */
    void HandleClosePressed(StringHash eventType,VariantMap& eventData)
    {
        engine_->Exit();
    }
    /**
    * Your non-rendering logic should be handled here.
    * This could be moving objects, checking collisions and reaction, etc.
    */
    void HandleUpdate(StringHash eventType,VariantMap& eventData)
    {
        float timeStep=eventData[Update::P_TIMESTEP].GetFloat();
        framecount_++;
        time_+=timeStep;
        // Movement speed as world units per second
        float MOVE_SPEED=10.0f;
        // Mouse sensitivity as degrees per M_PIxel
        const float MOUSE_SENSITIVITY=0.1f;

        Input* input=GetSubsystem<Input>();
        //if(input->GetQualifierDown(1))  // 1 is shift, 2 is ctrl, 4 is alt
        MOVE_SPEED/=10;
        if(input->GetKeyDown(KEY_W)){
            //cameraNodes[0]->Translate(Vector3(0,0, 1)*MOVE_SPEED*timeStep);
            //cameraNodes[1]->Translate(Vector3(0,0, 1)*MOVE_SPEED*timeStep);
            //cameraNodes[2]->Translate(Vector3(0,0, 1)*MOVE_SPEED*timeStep);
            //cameraNodes[3]->Translate(Vector3(0,0, 1)*MOVE_SPEED*timeStep);
        }
        if(input->GetKeyDown(KEY_S)){
            //cameraNodes[0]->Translate(Vector3(0,0, -1)*MOVE_SPEED*timeStep);
            //cameraNodes[1]->Translate(Vector3(0,0, -1)*MOVE_SPEED*timeStep);
            //cameraNodes[2]->Translate(Vector3(0,0, -1)*MOVE_SPEED*timeStep);
            //cameraNodes[3]->Translate(Vector3(0,0, -1)*MOVE_SPEED*timeStep);
	}
	/*
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
       // if(input->GetKeyDown(KEY_UP)){

//	}*/

    }

    void HandlePostUpdate(StringHash eventType,VariantMap& eventData)
    {
        // We really don't have anything useful to do here for this example.
        // Probably shouldn't be subscribing to events we don't care about.
    }

    void HandleRenderUpdate(StringHash eventType, VariantMap & eventData)
    {
        // We really don't have anything useful to do here for this example.
        // Probably shouldn't be subscribing to events we don't care about.
    }

    void HandlePostRenderUpdate(StringHash eventType, VariantMap & eventData)
    {
        // We could draw some debuggy looking thing for the octree.
        // scene_->GetComponent<Octree>()->DrawDebugGeometry(true);
    }

    void HandleEndFrame(StringHash eventType,VariantMap& eventData)
    {
        // We really don't have anything useful to do here for this example.
        // Probably shouldn't be subscribing to events we don't care about.
    }
};

URHO3D_DEFINE_APPLICATION_MAIN(Controller)

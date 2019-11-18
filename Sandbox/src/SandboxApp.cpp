#include <GameEngine.h>




// testing
class ExampleLayer : public GameEngine::Layer
{

public:

	ExampleLayer() : Layer() {}

	void onUpdate() override
	{
		LOG_INFO("ExampleLayer::update");
	}

	void onEvent(GameEngine::Event& e) override
	{
		LOG_TRACE("{0}", e);
	}

};
// testing








class Sandbox : public GameEngine::Application
{

public:

	Sandbox()
	{
		//pushLayer(new ExampleLayer());
		pushOverlay(new GameEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

GameEngine::Application* GameEngine::createApplication()
{
	return new Sandbox();
}
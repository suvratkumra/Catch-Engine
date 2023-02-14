#include <Catch.h>
#include <memory>

class Sandbox : public Catch::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Catch::Application* Catch::CreateApplication()
{
	return new Sandbox();
}
// This in detail adds everything there is in the engine files, just adding one Catch.h includes everything.
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

// the function which is responsible to draw the main screen from Catch Engine library.
std::unique_ptr<Catch::Application> Catch::CreateApplication()
{
	std::unique_ptr<Sandbox> sandbox;
	return sandbox;
}
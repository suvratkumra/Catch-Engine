#pragma once
#include <memory>

// we want our catch engine to create the application for us.
#ifdef CATCH_PLATFORM_WINDOWS

// we want to say that somewhere the application will be created and will be sent back to here
extern Catch::Application* Catch::CreateApplication();


int main(int argc, char** argv)
{
	std::cout << "Welcome to Catch Engine\n";
	auto app = Catch::CreateApplication();
	app->Run();
	delete(app);
	return 0;
}

#endif
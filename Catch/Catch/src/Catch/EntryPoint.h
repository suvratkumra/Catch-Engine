#pragma once
#include <memory>

// we want our catch engine to create the application for us.
// and it should only work on windows.
#ifdef CATCH_PLATFORM_WINDOWS

// we want to say that somewhere the application will be created and will be sent back to here
extern std::unique_ptr<Catch::Application> Catch::CreateApplication();


int main(int argc, char** argv)
{
	Catch::Log::Init();
	CLIENT_ERROR("This message is from client");
	CORE_INFO("This message is from Catch Engine");
	//std::cout << "Welcome to Catch Engine\n";
	auto app = Catch::CreateApplication();
	app->Run();
	return 0;
}

#endif
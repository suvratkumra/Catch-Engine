#pragma once

#include "Core.h"

namespace Catch {

	class CATCH_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	};

	// To be defined in a client
	Application* CreateApplication();


}
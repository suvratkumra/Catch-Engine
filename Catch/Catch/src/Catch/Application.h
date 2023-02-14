#pragma once

#include "Core.h"
#include <memory>

namespace Catch {

	class CATCH_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	};

	// To be defined in a client
	std::unique_ptr<Application> CreateApplication();


}
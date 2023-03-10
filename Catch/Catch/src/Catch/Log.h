#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Catch {

	class CATCH_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_client_logger_;
		static std::shared_ptr<spdlog::logger> s_core_logger_;

	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger_; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger_; }
	};

}

// Core log macros
#define CORE_ERROR(...) ::Catch::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_WARN(...) ::Catch::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_INFO(...) ::Catch::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_TRACE(...) ::Catch::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CLIENT_ERROR(...) ::Catch::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_WARN(...) ::Catch::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_INFO(...) ::Catch::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_TRACE(...) ::Catch::Log::GetClientLogger()->trace(__VA_ARGS__)


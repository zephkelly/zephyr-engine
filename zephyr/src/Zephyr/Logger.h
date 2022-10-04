#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Zephyr		{

		class ZEPHYR_API Logger
		{
		public:
				static void Init();

				inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
				inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		private:
				static std::shared_ptr<spdlog::logger> s_CoreLogger;
				static std::shared_ptr<spdlog::logger> s_ClientLogger;
		};
}

//Core logging macros
#define ZR_CORE_TRACE(...)		::Zephyr::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define ZR_CORE_INFO(...)			::Zephyr::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define ZR_CORE_WARN(...)			::Zephyr::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define ZR_CORE_ERROR(...)		::Zephyr::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define ZR_CORE_FATAL(...)		::Zephyr::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

#define ZR_TRACE(...)		::Zephyr::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define ZR_INFO(...)			::Zephyr::Logger::GetClientLogger()->info(__VA_ARGS__)
#define ZR_WARN(...)			::Zephyr::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define ZR_ERROR(...)		::Zephyr::Logger::GetClientLogger()->error(__VA_ARGS__)
#define ZR_FATAL(...)		::Zephyr::Logger::GetClientLogger()->fatal(__VA_ARGS__)

#pragma once

#ifdef ZR_PLATFORM_WINDOWS
	#ifdef ZR_BUILD_DLL
		#define ZEPHYR_API __declspec(dllexport)
	#else
		#define ZEPHYR_API __declspec(dllimport)
	#endif
#else
	#error Zephyr only supports windows
#endif
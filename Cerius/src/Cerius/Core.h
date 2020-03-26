#pragma once
#if !defined(_INC_CORE)
	#define _INC_CORE
	#if defined(CRS_PLATFORM_WINDOWS)
		#if defined(CRS_BUILD_DLL)
			#define CERIUS_API __declspec(dllexport)
		#else
			#define CERIUS_API __declspec(dllimport)
		#endif
	#else
		#error Cerius currently only supports windows!
	#endif
#endif
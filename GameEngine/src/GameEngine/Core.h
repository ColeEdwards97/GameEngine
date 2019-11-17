#pragma once


#ifdef GE_PLATFORM_WINDOWS

	#ifdef GE_BUILD_DLL
		#define GAMEENGINE_API __declspec(dllexport)		
	#else 
		#define GAMEENGINE_API __declspec(dllimport)
	#endif

#else
	#error Only supports Windows for now!
#endif

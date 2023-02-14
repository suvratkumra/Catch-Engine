#pragma once

/*
* The lines of code below will make sure that if you are using a Project which has Catch.dll attached, calling CATCH_API does the dllimport, and when you are in Catch.dll then it uses dllexport.
*/
#ifdef CATCH_PLATFORM_WINDOWS
#ifdef CATCH_BUILD_DLL
#define CATCH_API __declspec(dllexport)		// this means that we are in the Catch project which is a dll library.
#else
#define CATCH_API __declspec(dllimport)
#endif
#endif
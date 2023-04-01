#ifndef FMODAUDIOENGINE_H
#define FMODAUDIOENGINE_H

#ifdef WIN32
#include "fmod.hpp"
#include "fmod_errors.h"
#include "fmod/FMODAudioEngine.h"
#endif

#ifdef ANDROID
#include "fmod.hpp"
#include "fmod_errors.h"
#endif

#include <functional>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include "base/CCRef.h"

enum FMODAudioEventType
{
	STOP
};

class AX_DLL FMODAudioEngine : public axmol::Ref
{
public:
	// Create the main system object.
	static FMODAudioEngine* getInstance();

	static void destroyInstance();
	bool lazyInit();

private:
	FMODAudioEngine();
	~FMODAudioEngine();
};

#endif
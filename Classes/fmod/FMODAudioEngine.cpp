#include "FMODAudioEngine.h"
#include "cocos2d.h"
#include <fstream>
#include <iostream>
#include <string>

void ERRCHECK_fn(FMOD_RESULT result, const char* file, int line) {
	if (result != FMOD_OK)
	{
		CCLOG("%s(%d): FMOD error %d", file, line, result);
	}
}
#define ERRCHECK(_result) ERRCHECK_fn(_result, __FILE__, __LINE__)

static FMODAudioEngine* m_instance = nullptr;

FMODAudioEngine::FMODAudioEngine()
{
}

FMODAudioEngine* FMODAudioEngine::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new FMODAudioEngine();
		m_instance->lazyInit();
	}

	return m_instance;
}

FMODAudioEngine::~FMODAudioEngine()
{
	ax::log("automatically released");
}

void FMODAudioEngine::destroyInstance()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = 0;
	}
}

bool FMODAudioEngine::lazyInit()
{
	FMOD_RESULT result;
	FMOD::System* system = NULL;

	result = FMOD::System_Create(&system);      // Create the main system object.
	/*if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}*/
	AXLOG("%s", __FILE__);
	ERRCHECK(result);

	result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
	ax::log("working");
	return true;
}
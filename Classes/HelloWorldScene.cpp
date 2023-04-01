#include "HelloWorldScene.h"

USING_NS_AX;

bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = _director->getVisibleSize();
	auto origin = _director->getVisibleOrigin();
	auto safeArea = _director->getSafeAreaRect();
	auto safeOrigin = safeArea.origin;
	//auto obj_1 = FMODAudioEngine::getInstance();

	{
		auto obj_1 = FMODAudioEngine::getInstance();
	}
	return true;
}
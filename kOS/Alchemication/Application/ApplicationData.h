#pragma once
#include "Config/pch.h"

struct WindowSettings {
	int windowWidth;
	int windowHeight;
	int gameResWidth;
	int gameResHeight;
	utility::GUID startScene;

	REFLECTABLE(WindowSettings, windowWidth, windowHeight, gameResWidth, gameResHeight, startScene);
};

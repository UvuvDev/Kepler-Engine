#pragma once

#include <stdint.h>
#include <memory>
#include <unordered_map>
#include <string>

#include "raylib.h"

class AnimationHandler {

	uint8_t framesPerSecond;
	std::vector<std::shared_ptr<Texture2D>> textureVector;

	AnimationHandler(std::string textureMapKeys);

	//AnimationHandler(std::string textureMapKeys);

};
#pragma once

#include <stdint.h>
#include <memory>
#include <unordered_map>
#include <string>

#include "raylib.h"

class AnimationHandlerClass {
private:

	int framesPerSecond;

	int pixelDensityPerChunk;

	bool shouldUpdate;

	int timeStuff;

	std::vector<std::shared_ptr<Texture2D>> textureVector;

	Vector2 chunksPerSheet;

	Vector2 currentChunk;

public:

	Texture2D testTexture = LoadTexture("resources/testspritesheet.png");

	AnimationHandlerClass();

	AnimationHandlerClass(std::string textureMapKeys);

	std::shared_ptr<Texture2D> testTexturePtr;

	//AnimationHandler(std::string textureMapKeys);

	void update();

	void freezeFrame();

	void freezeFrame(Vector2 frameToFreezeOn);

	Vector2 spriteToUse();

	Vector2 getCurrentChunk();

	int getPixelDensityPerChunk();



};
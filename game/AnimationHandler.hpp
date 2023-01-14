#pragma once

#include <stdint.h>
#include <memory>
#include <unordered_map>
#include <string>

#include "raylib.h"

class AnimationHandlerClass {
private:

	static constexpr int defaultFPS = 10;

	double framesPerSecond = 5;

	int pixelDensityPerChunk;

	bool shouldUpdate;

	bool isFrozen = false;

	float timeSinceLastUpdate;

	float currentFrame;

	std::vector<std::shared_ptr<Texture2D>> textureVector;

	Vector2 chunksPerSheet;

	Vector2 currentChunk;

	Vector2 directionsToFlow;

public:

	Texture2D testTexture = LoadTexture("resources/testspritesheet.png");

	AnimationHandlerClass();

	AnimationHandlerClass(std::string textureMapKeys);

	std::shared_ptr<Texture2D> testTexturePtr;

	//AnimationHandler(std::string textureMapKeys);

	void update();

	void freezeFrame();

	void freezeFrame(Vector2 frameToFreezeOn);

	void unfreezeFrame();

	Vector2 spriteToUse();

	Vector2 getCurrentChunk();

	int getPixelDensityPerChunk();

	void setCurrentChunk(Vector2 newchunk);

	void setChunkMovement(Vector2 newDirectionsToFlow);



};
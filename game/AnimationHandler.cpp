#include "AnimationHandler.hpp"
#include <iostream>


AnimationHandlerClass::AnimationHandlerClass() {
	
	framesPerSecond = 2;
	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };
	directionsToFlow = { 0, 1 };
	currentFrame = 1;

	timeStuff = 0;

	testTexture = LoadTexture("checkmark.png");

	shouldUpdate = false;

}


AnimationHandlerClass::AnimationHandlerClass(std::string textureMapKeys) {

	timeStuff = 0;

	framesPerSecond = 2;
	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };
	directionsToFlow = { 0, 1 };

	shouldUpdate = false;

}

void AnimationHandlerClass::update() {

	float currentTimeInMillis = std::round(GetTime()) - GetTime();

	std::cout << "Current Anim Time:  " << currentTimeInMillis << "     ";
	std::cout << "Current Frame Time:  " << ((1 / framesPerSecond) * currentFrame) << "     ";

	if (currentTimeInMillis > ((1 / framesPerSecond) * currentFrame)) {
		shouldUpdate = true;
		currentFrame++;
	}

	else {
		shouldUpdate = false;
	}



	if (currentFrame > framesPerSecond) {
		currentFrame = 1;
	}


	if (shouldUpdate == true) {

		if (currentChunk.x > chunksPerSheet.x * pixelDensityPerChunk) {
			currentChunk.x = 0.f;
		}
		else {
			currentChunk.x += directionsToFlow.x * pixelDensityPerChunk;
		}

		if (currentChunk.y > chunksPerSheet.y * pixelDensityPerChunk) {
			currentChunk.y = 0.f;
		}
		else {
			currentChunk.y += directionsToFlow.y * pixelDensityPerChunk;
		}

	}

	shouldUpdate = false;

}

Vector2 AnimationHandlerClass::spriteToUse() {

	return { pixelDensityPerChunk * currentChunk.x , pixelDensityPerChunk * currentChunk.y };

}

Vector2 AnimationHandlerClass::getCurrentChunk() {

	return currentChunk;

}

int AnimationHandlerClass::getPixelDensityPerChunk() {
	return pixelDensityPerChunk;
}

void AnimationHandlerClass::freezeFrame() {
	timeStuff = 29;
	shouldUpdate = false;
}

void AnimationHandlerClass::freezeFrame(Vector2 frameToFreezeOn) {
	timeStuff = 29;
	shouldUpdate = false;

	currentChunk = frameToFreezeOn;

}

void AnimationHandlerClass::setCurrentChunk(Vector2 newChunkArg) {
	currentChunk = newChunkArg;
}

void AnimationHandlerClass::setChunkMovement(Vector2 newDirectionsToFlow) {
	directionsToFlow = newDirectionsToFlow;
}
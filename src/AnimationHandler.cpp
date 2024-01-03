#include "AnimationHandler.hpp"
#include <iostream>


AnimationHandlerClass::AnimationHandlerClass() {
	
	framesPerSecond = defaultFPS;
	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };
	directionsToFlow = { 0, 1 };
	currentFrame = std::floor(GetTime());

	testTexture = LoadTexture("checkmark.png");

	shouldUpdate = false;

}


AnimationHandlerClass::AnimationHandlerClass(std::string textureMapKeys) {

	framesPerSecond = defaultFPS;

	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };
	directionsToFlow = { 0, 1 };

	currentFrame = 1;

	shouldUpdate = false;

}

void AnimationHandlerClass::update() {

	/*
	framesPerSecond = 2;

	currentTimeInMillis = GetTime() - std::floor(GetTime());

	std::cout << "Current Anim Time:  " << currentTimeInMillis << "     ";
	std::cout << "Current Frame Time:  " << ((1 / framesPerSecond) * currentFrame) << "     ";

	if (currentTimeInMillis > ((1 / framesPerSecond)) * currentFrame) {
		shouldUpdate = true;

		std::cout << "\n\n EIFHWIOFJOIEOFWQJIFQOIFWEQF";
		currentFrame++;
	}

	else {
		shouldUpdate = false;
	}

	std::cout << "   Current Frame:   " << currentFrame << "   ";
	std::cout << "   FPS:   " << framesPerSecond << "   ";

	if (currentFrame >= framesPerSecond) {
		currentFrame = 1;
	}
	else {
		//currentFrame = 1;
	}
	
	*/


	std::cout << "Current Frame Time:  " << ((1 / framesPerSecond) * currentFrame) << "     ";


	if (GetTime() > currentFrame / framesPerSecond) {
		currentFrame++;
		shouldUpdate = true;
	}
	else {
		shouldUpdate = false;
	}


	if (shouldUpdate == true && !isFrozen) {

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
	isFrozen = true;
}

void AnimationHandlerClass::freezeFrame(Vector2 frameToFreezeOn) {
	isFrozen = true;
	currentChunk = frameToFreezeOn;

}

void AnimationHandlerClass::unfreezeFrame() {
	isFrozen = false;
}

void AnimationHandlerClass::setCurrentChunk(Vector2 newChunkArg) {
	currentChunk = newChunkArg;
}

void AnimationHandlerClass::setChunkMovement(Vector2 newDirectionsToFlow) {
	directionsToFlow = newDirectionsToFlow;
}
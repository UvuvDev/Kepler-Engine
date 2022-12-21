#include "AnimationHandler.hpp"
#include <iostream>


AnimationHandlerClass::AnimationHandlerClass() {
	
	framesPerSecond = 1;
	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };
	directionsToFlow = { 0, 1 };

	timeStuff = 0;

	testTexturePtr = std::make_shared<Texture2D>(testTexture);

	shouldUpdate = false;

}


AnimationHandlerClass::AnimationHandlerClass(std::string textureMapKeys) {

	timeStuff = 0;

	framesPerSecond = 12;
	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };
	directionsToFlow = { 0, 1 };

	shouldUpdate = false;

}

void AnimationHandlerClass::update() {		

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

	/*std::cout << "\n\n" <<

		"Current X Chunk: " << currentChunk.x <<
		" Current Y Chunk: " << currentChunk.y << "\n\n";

	std::cout << "\n\n" <<

		"Amount of X Chunks: " << chunksPerSheet.y <<
		" Amount of Y Chunks: " << chunksPerSheet.y << "\n\n"; */

	if (std::round( GetTime() ) / framesPerSecond > GetTime() / framesPerSecond) {
		shouldUpdate = true;
		timeStuff = 0;
	}

	else {
		timeStuff++;
		shouldUpdate = false;
	}


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
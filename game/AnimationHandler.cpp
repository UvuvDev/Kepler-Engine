#include "AnimationHandler.hpp"
#include <iostream>


AnimationHandlerClass::AnimationHandlerClass() {
	framesPerSecond = 12;
	pixelDensityPerChunk = 64;
	chunksPerSheet = { 4, 5 };
	currentChunk = { 0, 0 };

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

}

void AnimationHandlerClass::update() {		

	if (shouldUpdate == true) {
		if (currentChunk.x > chunksPerSheet.x * pixelDensityPerChunk) {
			currentChunk.x = 0.f;
		}
		else {
			currentChunk.x += 0.f;
		}

		if (currentChunk.y > chunksPerSheet.y * pixelDensityPerChunk) {
			currentChunk.y = 0.f;
		}
		else {
			currentChunk.y += pixelDensityPerChunk;
		}
	}

	/*std::cout << "\n\n" <<

		"Current X Chunk: " << currentChunk.x <<
		" Current Y Chunk: " << currentChunk.y << "\n\n";

	std::cout << "\n\n" <<

		"Amount of X Chunks: " << chunksPerSheet.y <<
		" Amount of Y Chunks: " << chunksPerSheet.y << "\n\n"; */



	


	if (timeStuff > 30) {
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
#pragma once

#include "raylib.h"
#include <vector>

class AudioController {
private:
	
	void update();

public:
	
	AudioController();

	
	void playSound(Sound soundToPlay);

	void stopAllSound();

};
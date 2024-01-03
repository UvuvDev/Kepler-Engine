#pragma once
#include "BaseClass.hpp"
#include "raylib.h"

class Item : BaseClass {
private:
	
	int itemCount;
	Texture2D itemTexture;

	bool isAffectedByGravity;

public:

	bool getIfGravity();


};
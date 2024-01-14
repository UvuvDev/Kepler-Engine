#pragma once
#include "raylib-include/raylib.h"
#include "Platform.hpp"
#include <unordered_map>
#include "GlobalKeys.hpp"

class GlobalHitboxHandler {
private:

    std::unordered_map<int, BaseClass*> globalHitboxMap;

public:

    GlobalHitboxHandler();

    std::unordered_map<int, BaseClass*> getHitboxMap();

};

class Level {
private:

	std::unordered_map<int, Rectangle, BaseClass*> globalHitboxMap;

	std::vector<Rectangle> globalHitboxes;

public:
	
	Platforms platforms;

	Level();

	void update();

	void reset();

	void newGlobalHitbox(GlobalHitboxHandler* hitboxHand);

	std::vector<Rectangle> coordsToCheckCollision(Vector2 coords);



};
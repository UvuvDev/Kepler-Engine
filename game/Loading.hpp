#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

#include "raylib.h"
#include "raygui.h"


class BaseLoader {
public:

	uint8_t progressLoading;

	virtual bool load() = 0;

};

class Loader : BaseLoader {
private:

	
public:

	bool load();	

	std::unordered_map<std::string, std::shared_ptr<Texture2D>> textureMap;
	std::unordered_map<std::string, std::shared_ptr<Music>> musicMap;
	std::unordered_map<std::string, std::shared_ptr<AudioCallback>> audioMap;


};

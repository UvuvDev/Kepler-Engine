#pragma once
#include "BaseClass.hpp"
#include "Socket.h"
#include "raylib-include/raylib.h"
#include <string>

class Item : public BaseClass {
protected:
	
	int itemCount;
    std::string name = "NO_NAME";
	Texture2D itemTexture;

	bool isAffectedByGravity;

    KeplerSocket* socket;

public:

    Item();

    Item(std::string nameArg, Texture2D textureArg, bool isGravity, KeplerSocket* socket);

	virtual bool getIfGravity() = 0;

    virtual void update() = 0;

    virtual void setSocket(KeplerSocket* socketArg) = 0;

    virtual void setPos(Vector2 pos) = 0;


};
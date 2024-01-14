#include "include/Item.hpp"

Item::Item() {
    itemTexture = LoadTexture("resources/KeplerEngineLogo.png");

}

Item::Item(std::string nameArg, Texture2D textureArg, bool isGravity, KeplerSocket* socket) {
    name = nameArg;
    itemTexture = textureArg;
    isAffectedByGravity = isGravity;
    this->socket = socket;
    itemCount = 1;

}

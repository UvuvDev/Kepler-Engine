
#include "non-library-includes/ElementalSword.hpp"

ElementalSword::ElementalSword() {

    damage = defaultDamage;
    range = defaultRange;
    isLockedToSocket = false;

    texture = LoadTexture("resources/watersword.png");

    colorHue = RAYWHITE;

    collisionBox = { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) };

    if (socket == nullptr) {

    }
    else {
        socket->isFlipped = false;
    }



}

ElementalSword::ElementalSword(Element elementArg, float damageArg) {

    damage = damageArg;
    range = defaultRange;
    isLockedToSocket = false;

    texture = LoadTexture("resources/watersword.png");

    colorHue = RAYWHITE;

    collisionBox = { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) };

    if (socket == nullptr) {

    }
    else {
        socket->isFlipped = false;
    }

}

ElementalSword::ElementalSword(Element elementArg, float damageArg, float rangeArg, KeplerSocket* socketArg) {

    damage = defaultDamage;
    range = defaultRange;
    isLockedToSocket = false;

    socket = socketArg;

    texture = LoadTexture("resources/weapon.png");

    colorHue = RAYWHITE;

    collisionBox = { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) };

    socket->isFlipped = false;

}

void ElementalSword::setPos(Vector2 pos) {
    isLockedToSocket = false;
    coords = pos;

}

void ElementalSword::setSocket(KeplerSocket* socketArg) {
    isLockedToSocket = true;
    socket = socketArg;
}

void ElementalSword::attack(int* health) {
    health--;

}

void ElementalSword::update() {

    if (isLockedToSocket) {
        coords = *socket->coords;
    }
    else {
        //	Do nothing
    }

    DrawTexture(texture, coords.x, coords.y, colorHue);
    DrawRectangleLines(coords.x- 32, coords.y- 32, // Bottom
                       64, 64, RED);

}

void ElementalSword::reset() {

}

bool ElementalSword::getIfGravity() {
    return isAffectedByGravity;
}
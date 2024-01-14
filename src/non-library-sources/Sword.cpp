//
// Created by Mavericks on 1/13/2024.
//

#include "non-library-includes/Sword.hpp"


void Sword::setPos(Vector2 pos) {
    isLockedToSocket = false;
    coords = pos;

}

void Sword::setSocket(KeplerSocket* socketArg) {
    isLockedToSocket = true;
    socket = socketArg;
}

void Sword::attack(int* health) {
    health--;

}

void Sword::update() {

    if (isLockedToSocket) {
        coords = *socket->coords;
    }
    else {
        //	Do nothing
    }

    DrawTexture(texture, coords.x, coords.y, colorHue);

}

void Sword::reset() {

}
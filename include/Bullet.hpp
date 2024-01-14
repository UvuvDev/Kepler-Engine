//
// Created by Mavericks on 8/17/2023.
//

#ifndef KEPLERENGINE_BULLET_HPP
#define KEPLERENGINE_BULLET_HPP

#pragma once

#include "raylib-include/raylib.h"

class Bullet {
protected:

    Texture2D texture;

    Vector2 coords;

    Vector2 movementVector;

public:

    Bullet(Vector2 coordsArg, Texture2D textureArg);

    void setMovementVector(Vector2* movementVectorArg);

    void update();

    Vector2 getCoords();

};

#endif //KEPLERENGINE_BULLET_HPP

#pragma once

#include "Weapon.hpp"

class Sword : public Weapon {
protected:

public:

    virtual void setPos(Vector2 pos) = 0;

    virtual void setSocket(KeplerSocket* socketArg) = 0;

    virtual void update() = 0;

    virtual void reset() = 0;

    virtual void attack(int* health) = 0;

    virtual bool getIfGravity() = 0;

};
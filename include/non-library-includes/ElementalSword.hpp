#pragma once

#include "Sword.hpp"

enum class Element {
    normal = 0,
    fire,
    water,
    ice,
    earth,
    darkness,
    light,
    air
};

class ElementalSword : public Sword {
protected:

    Element element = Element::normal;

public:

    ElementalSword();

    ElementalSword(Element elementArg, float damage);

    ElementalSword(Element elementArg, float damageArg, float rangeArg, KeplerSocket* socketArg);

    void setPos(Vector2 pos) override;

    void setSocket(KeplerSocket* socketArg) override;

    void update() override;

    void reset() override;

    void attack(int* health) override;

    bool getIfGravity() override;

};
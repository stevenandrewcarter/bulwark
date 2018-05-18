#ifndef BULWARK_GAMEMAP_H
#define BULWARK_GAMEMAP_H

#include <list>
#include "vendor/json.h"

using nlohmann::json;

class Missle {
public:
    int damage;
    int speed;
    int x;
    int y;
    std::string playerType;
};

class Building {
public:
    int health;
    int constructionTimeLeft;
    int price;
    int weaponDamage;
    int weaponSpeed;
    int weaponCooldownTimeLeft;
    int weaponCooldownPeriod;
    int destroyMultiplier;
    int constructionScore;
    int energyGeneratedPerTurn;
    std::string buildingType;
    int x;
    int y;
    std::string playerType;
};


class GameMap {
public:
    int x;
    int y;
    std::list<Building> buildings;
    std::list<Missle> missles;
    std::string cellOwner;
};

void from_json(const json& j, GameMap& p);
void from_json(const json& j, Building& p);
void from_json(const json& j, Missle& p);

#endif //BULWARK_GAMEMAP_H

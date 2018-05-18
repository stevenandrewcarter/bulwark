#ifndef BULWARK_GAMEDETAILS_H
#define BULWARK_GAMEDETAILS_H

#include "vendor/json.h"

using nlohmann::json;

struct BuildingPrices {
    int DEFENSE;
    int ENERGY;
    int ATTACK;
};

struct GameDetails {
    int round;
    int mapWidth;
    int mapHeight;
    BuildingPrices buildingPrices;
};

void from_json(const json& j, GameDetails& p);
void from_json(const json& j, BuildingPrices &p);

#endif //BULWARK_GAMEDETAILS_H

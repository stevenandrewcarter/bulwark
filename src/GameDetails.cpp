#include "GameDetails.h"

void from_json(const json& j, GameDetails& p) {
    p.mapHeight = j.at("mapHeight").get<int>();
    p.mapWidth = j.at("mapWidth").get<int>();
    p.round = j.at("round").get<int>();
    p.buildingPrices = j.at("buildingPrices");
}

void from_json(const json& j, BuildingPrices& p) {
    p.ATTACK = j.at("ATTACK").get<int>();
    p.DEFENSE = j.at("DEFENSE").get<int>();
    p.ENERGY = j.at("ENERGY").get<int>();
}

#ifndef BULWARK_PLAYER_H
#define BULWARK_PLAYER_H

#include <string>

#include "vendor/json.h"

using nlohmann::json;

struct Player {
    std::string playerType;
    int energy;
    int health;
    int hitsTaken;
    int score;
};

void from_json(const json& j, Player& p);

#endif //BULWARK_PLAYER_H

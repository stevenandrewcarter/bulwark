#include "Player.h"


void from_json(const json& j, Player& p) {
    p.playerType = j.at("playerType").get<std::string>();
    p.energy = j.at("health").get<int>();
    p.health = j.at("health").get<int>();
    p.hitsTaken = j.at("hitsTaken").get<int>();
    p.score = j.at("score").get<int>();
}
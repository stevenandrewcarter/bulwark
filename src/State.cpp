#include "State.h"
#include <iostream>

using namespace std;

void from_json(const json &j, State &s) {
    s.gameDetails = j.at("gameDetails");
    cout << "Loaded GameDetails" << endl;
    std::for_each(j["players"].begin(), j["players"].end(), [&s](const json &player) {
        Player p = player;
        s.players.push_back(p);
    });
    cout << "Loaded Players" << endl;
    s.gameMap = j.at("gameMap");
    cout << "Loaded GameMap" << endl;
}

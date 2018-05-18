#ifndef BULWARK_STATE_H
#define BULWARK_STATE_H


#include <list>
#include "GameDetails.h"
#include "Player.h"
#include "GameMap.h"

class State {
public:
    GameDetails gameDetails;
    std::list<Player> players;
    GameMap gameMap;
};

void from_json(const json& j, State& s);

#endif //BULWARK_STATE_H

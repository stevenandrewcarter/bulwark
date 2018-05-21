#ifndef BULWARK_STATE_H
#define BULWARK_STATE_H

#include "vendor/json.h"
#include <list>
#include <string>

using namespace std;
using json = nlohmann::json;

namespace Bulwark {
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

    struct Player {
        std::string playerType;
        int energy;
        int health;
        int hitsTaken;
        int score;
        std::map<int, double> cellCost;
    };

    struct Missile {
        int damage;
        int speed;
        int x;
        int y;
        std::string playerType;
    };

    struct Building {
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

    struct Cell {
        int x;
        int y;
        std::list<Building> buildings;
        std::list<Missile> missiles;
        std::string cellOwner;

        double calculateCost();
    };

    struct GameMap {
        std::map<int, std::map<int, Cell>> cells;
    };

    struct State {
        GameDetails gameDetails;
        std::list<Player> players;
        GameMap gameMap;

        void calculateCellCosts();
        Player *getPlayer(const std::string &playerType);
    };

    void from_json(const json &j, Player &p);

    void from_json(const json &j, State &s);

    void from_json(const json &j, GameDetails &p);

    void from_json(const json &j, BuildingPrices &p);

    void from_json(const json &j, GameMap &p);

    void from_json(const json &j, Building &p);

    void from_json(const json &j, Missile &p);
}

#endif //BULWARK_STATE_H

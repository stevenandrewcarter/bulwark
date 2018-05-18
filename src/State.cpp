#include "State.h"
#include <iostream>

namespace Bulwark {

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

    void from_json(const json &j, Player &p) {
        p.playerType = j.at("playerType").get<std::string>();
        p.energy = j.at("health").get<int>();
        p.health = j.at("health").get<int>();
        p.hitsTaken = j.at("hitsTaken").get<int>();
        p.score = j.at("score").get<int>();
    }

    void from_json(const json &j, GameDetails &p) {
        p.mapHeight = j.at("mapHeight").get<int>();
        p.mapWidth = j.at("mapWidth").get<int>();
        p.round = j.at("round").get<int>();
        p.buildingPrices = j.at("buildingPrices");
    }

    void from_json(const json &j, BuildingPrices &p) {
        p.ATTACK = j.at("ATTACK").get<int>();
        p.DEFENSE = j.at("DEFENSE").get<int>();
        p.ENERGY = j.at("ENERGY").get<int>();
    }

    void from_json(const json &j, GameMap &p) {
        cout << j << endl;
        for_each(j.begin(), j.end(), [&p](const json &rows) {
            for_each(rows.begin(), rows.end(), [&p](const json &cell) {
                p.x = cell.at("x").get<int>();
                p.y = cell.at("y").get<int>();
                cout << "Loading row " << p.x << " " << p.y << endl;
                p.cellOwner = cell.at("cellOwner").get<string>();
                for_each(cell["buildings"].begin(), cell["buildings"].end(), [&p](const json &building) {
                    cout << building << endl;
                    Building b = building;
                    p.buildings.push_back(b);
                });
                cout << "Loaded buildings" << endl;
                for_each(cell["missiles"].begin(), cell["missiles"].end(), [&p](const json &missle) {
                    cout << missle << endl;
                    Missle m = missle;
                    p.missles.push_back(m);
                });
                cout << "Loaded missiles" << endl;
            });
            cout << rows << endl;
        });
    }

    void from_json(const json &j, Building &b) {
        b.health = j.at("health").get<int>();
        b.constructionTimeLeft = j.at("constructionTimeLeft").get<int>();
        b.price = j.at("price").get<int>();
        b.weaponDamage = j.at("weaponDamage").get<int>();
        b.weaponSpeed = j.at("weaponSpeed").get<int>();
        b.weaponCooldownTimeLeft = j.at("weaponCooldownTimeLeft").get<int>();
        b.weaponCooldownPeriod = j.at("weaponCooldownPeriod").get<int>();
        b.destroyMultiplier = j.at("destroyMultiplier").get<int>();
        b.constructionScore = j.at("constructionScore").get<int>();
        b.energyGeneratedPerTurn = j.at("energyGeneratedPerTurn").get<int>();
        b.buildingType = j.at("buildingType").get<std::string>();
        b.x = j.at("x").get<int>();
        b.y = j.at("y").get<int>();
        b.playerType = j.at("playerType").get<std::string>();
    }

    void from_json(const json &j, Missle &m) {
        m.damage = j.at("damage").get<int>();
        m.speed = j.at("speed").get<int>();
        m.x = j.at("x").get<int>();
        m.y = j.at("y").get<int>();
        m.playerType = j.at("playerType").get<string>();
    }
}
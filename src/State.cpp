#include "State.h"
#include <iostream>
#include "vendor/spdlog/spdlog.h"

namespace spd = spdlog;
namespace Bulwark {
    auto console = spd::stdout_color_mt("console");

    void from_json(const json &j, State &s) {
        console->info("Loading State!");
        s.gameDetails = j.at("gameDetails");
        console->info("Loaded GameDetails");
        std::for_each(j.at("players").begin(), j.at("players").end(), [&s](const json &player) {
            Player p = player;
            s.players.push_back(p);
        });
        console->info("Loaded Players");
        s.gameMap = j.at("gameMap");
        console->info("Loaded GameMap");
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
        for_each(j.begin(), j.end(), [&p](const json &rows) {
            for_each(rows.begin(), rows.end(), [&p](const json &cell) {
                p.x = cell.at("x").get<int>();
                p.y = cell.at("y").get<int>();
                console->info("Loading row {0:d} {1:d}", p.x, p.y);
                p.cellOwner = cell.at("cellOwner").get<string>();
                for_each(cell.at("buildings").begin(), cell.at("buildings").end(), [&p](const json &building) {
                    Building b = building;
                    p.buildings.push_back(b);
                });
                console->info("Loaded buildings");
                for_each(cell.at("missiles").begin(), cell.at("missiles").end(), [&p](const json &missle) {
                    Missle m = missle;
                    p.missles.push_back(m);
                });
                console->info("Loaded missiles");
            });
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
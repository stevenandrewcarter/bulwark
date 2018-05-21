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
        for_each(j.at("players").begin(), j.at("players").end(), [&s](const json &player) {
            Player p = player;
            s.players.push_back(p);
        });
        console->info("Loaded Players");
        s.gameMap = j.at("gameMap");
        console->info("Loaded GameMap");
    }

    void from_json(const json &j, Player &p) {
        p.playerType = j.at("playerType").get<string>();
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
                Cell c;
                c.x = cell.at("x").get<int>();
                c.y = cell.at("y").get<int>();
                console->info("Loading row {0:d} {1:d}", c.x, c.y);
                c.cellOwner = cell.at("cellOwner").get<string>();
                for_each(cell.at("buildings").begin(), cell.at("buildings").end(), [&c](const json &building) {
                    Building b = building;
                    c.buildings.push_back(b);
                });
                for_each(cell.at("missiles").begin(), cell.at("missiles").end(), [&c](const json &missle) {
                    Missile m = missle;
                    c.missiles.push_back(m);
                });
                p.cells[c.x][c.y] = c;
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
        b.buildingType = j.at("buildingType").get<string>();
        b.x = j.at("x").get<int>();
        b.y = j.at("y").get<int>();
        b.playerType = j.at("playerType").get<string>();
    }

    void from_json(const json &j, Missile &m) {
        m.damage = j.at("damage").get<int>();
        m.speed = j.at("speed").get<int>();
        m.x = j.at("x").get<int>();
        m.y = j.at("y").get<int>();
        m.playerType = j.at("playerType").get<string>();
    }

    void State::calculateCellCosts() {
        for_each(this->gameMap.cells.begin(), this->gameMap.cells.end(), [this](std::pair<const int, std::map<int, Cell>> &cells) {
            for_each(cells.second.begin(), cells.second.end(), [this](std::pair<const int, Cell> &cell) {
                Player *player = getPlayer(cell.second.cellOwner);
                if (player != nullptr) {
                    player->cellCost[cell.second.y] += cell.second.calculateCost();
                }
            });
        });
    }

    Player *State::getPlayer(const std::string &playerType) {
        Player *player = nullptr;
        for_each(this->players.begin(), this->players.end(), [&player, &playerType](Player &p) {
            if (p.playerType == playerType) {
                player = &p;
            }
        });
        return player;
    }

    double Cell::calculateCost() {
        double cost = 0;
        // Calculate the building cost first
        for_each(this->buildings.begin(), this->buildings.end(), [&cost](const Building &b) {
            cost += b.constructionScore + b.health + b.weaponSpeed + b.weaponDamage + (b.weaponCooldownPeriod - b.weaponCooldownTimeLeft);
        });
        console->info("[{0:d} {1:d}] Calculating Cost: {2}", x, y, cost);
        return cost;
    }
}
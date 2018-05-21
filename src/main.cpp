#include <iostream>
#include <fstream>
#include "vendor/json.h"
#include "State.h"

int main() {
    json j;
    ifstream i("state.json");
    if (i.is_open()) {
        i >> j;
        Bulwark::State state = j;
        state.calculateCellCosts();
        for_each(state.players.begin(), state.players.end(), [](const Bulwark::Player &player) {
            cout << player.playerType << endl;
            for_each(player.cellCost.begin(), player.cellCost.end(), [](std::pair<int, double> cost) {
               cout << "[" << cost.first << " : " << cost.second << "] ";
            });
            cout << endl;
        });
    }
    return 0;
}
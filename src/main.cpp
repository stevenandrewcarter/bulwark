#include <iostream>
#include <fstream>
#include "vendor/json.h"
#include "GameDetails.h"

using json = nlohmann::json;
using namespace std;

int main() {
    json j;
    ifstream i("state.json");
    if (i.is_open()) {
        i >> j;
        cout << j << endl;
        GameDetails gd;
        gd = j["gameDetails"];
        cout << gd.mapHeight << endl;
        cout << gd.buildingPrices.ENERGY << endl;
    }
    cout << "Hello, World!" << endl;
    return 0;
}
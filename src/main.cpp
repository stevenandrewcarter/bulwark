#include <iostream>
#include <fstream>
#include "vendor/json.h"
#include "GameDetails.h"
#include "Player.h"
#include "GameMap.h"
#include "State.h"

using json = nlohmann::json;
using namespace std;

int main() {
    json j;
    ifstream i("state.json");
    if (i.is_open()) {
        i >> j;
        cout << j << endl;
        State state;
        state = j;
    }
    cout << "Hello, World!" << endl;
    return 0;
}
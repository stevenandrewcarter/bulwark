#include <iostream>
#include <fstream>
#include "vendor/json.h"
#include "State.h"

int main() {
    json j;
    ifstream i("state.json");
    if (i.is_open()) {
        i >> j;
        Bulwark::State state;
        state = j;
    }
    return 0;
}
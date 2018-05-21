#include "Agent.h"
#include "State.h

namespace Bulwark {
    Agent::Agent(State *state) {
        this->state = state;
    }

    void Agent::Calculate() {
        // Calculate the cost of the columns
        // Determine the strongest / weakest column
        // Decide if it wants to be aggressive or defensive (Depends on opponent)
        // Return Move
    }
}

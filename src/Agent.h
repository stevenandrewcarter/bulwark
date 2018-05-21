#ifndef BULWARK_AGENT_H
#define BULWARK_AGENT_H

namespace Bulwark {
    struct State;

/**
 * Bulwark agent will take a input state and calculate the move that
 * it will make for the output state.
 */
    class Agent {
    public:
        Agent(State *state);

        void Calculate();

    private:
        State *state;
    };
}
#endif //BULWARK_AGENT_H

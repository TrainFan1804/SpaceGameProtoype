//
// Created by o.le on 09.02.25.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <unordered_map>

/**
 * Instead of saving all bool flags in a class itself use this
 * statemachine to manage all flags externally. Just use this
 * when you need to save MULTIPLE flags. There is no need to use
 * this when just saving one flag.
 */
class StateMachine
{
public:
    /**
     * This method will always set the flag of the given state to false.
     *
     * @param state The saving state.
     */
    void setState(int state);
    void setState(int state, bool flag);

    /**
     * Return the flag of the entered state. If state not found return false.
     *
     * @param state The checked state.
     * @return  The flag of the checked state.
     */
    bool getState(int state) const;
private:
    std::unordered_map<int, bool> _states;
};

#endif //STATEMACHINE_H

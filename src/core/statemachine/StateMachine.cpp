//
// Created by o.le on 09.02.25.
//

#include "core/statemachine/StateMachine.h"

void StateMachine::setState(int state)
{
    setState(state, false);
}

void StateMachine::setState(int state, bool flag)
{
    _states[state] = flag;
}

bool StateMachine::getState(int state) const
{
    auto it = _states.find(state);
    if (it != _states.end())
        return it->second;
    return false;
}

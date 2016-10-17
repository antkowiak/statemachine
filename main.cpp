#include "statemachine.h"

void STATE_GREEN(const TStateName & fromState, const TTransitionName & transition, const TStateName & toState)
{
    std::cout << "IN STATE GREEN" << std::endl;
}

void STATE_YELLOW(const TStateName & fromState, const TTransitionName & transition, const TStateName & toState)
{
    std::cout << "IN STATE YELLOW" << std::endl;
}

void STATE_RED(const TStateName & fromState, const TTransitionName & transition, const TStateName & toState)
{
    std::cout << "IN STATE RED" << std::endl;
}

void TRANSITION_RED_TO_GREEN(const TStateName & prevState, const TTransitionName & transition, const TStateName & nextState)
{
    std::cout << "TRANSITION RED TO GREEN" << std::endl;
}

void TRANSITION_GREEN_TO_YELLOW(const TStateName & prevState, const TTransitionName & transition, const TStateName & nextState)
{
    std::cout << "TRANSITION GREEN TO YELLOW" << std::endl;
}

void TRANSITION_YELLOW_TO_RED(const TStateName & prevState, const TTransitionName & transition, const TStateName & nextState)
{
    std::cout << "TRANSITION YELLOW TO RED" << std::endl;
}

int main(int argc, char * argv[])
{
    Statemachine trafficLight("green");

    trafficLight.addState("green",   STATE_GREEN);
    trafficLight.addState("yellow",  STATE_YELLOW);
    trafficLight.addState("red",     STATE_RED);

    trafficLight.addTransition("red",    "change_color", "green",    TRANSITION_RED_TO_GREEN);
    trafficLight.addTransition("green",  "change_color", "yellow",   TRANSITION_GREEN_TO_YELLOW);
    trafficLight.addTransition("yellow", "change_color", "red",      TRANSITION_YELLOW_TO_RED);

    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");
    trafficLight.pushTransition("change_color");

    trafficLight.run();
    trafficLight.print();

    return 0;
}


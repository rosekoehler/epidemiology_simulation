#ifndef world_h
#define world_h

#include "agent.h"

// creates all agents in world
Agent* genesis(int population);

// takes in the array list of agents and the amount of starting infected agents
// returns pointer to list of infected agents
Agent* startInfect(Agent* agents, int pt_zero);

// increments days_infected for a single infected agent
void updateDaysInfected(Agent* agent);

#endif

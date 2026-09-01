#ifndef world_h
#define world_h
#include "agent.h"

// creates all agents in world
Agent* genesis(int population);

// takes in the array list of agents and the amount of starting infected agents
// returns pointer to list of of infected agents
Agent* startInfect(Agent*, int pt_zero);

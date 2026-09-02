#include <stdlib.h>
#include "world.h"

Agent* genesis(int population){
    Agent* agents = malloc(sizeof(Agent) * population);
    // TODO: initialize each agent's x, y, status, days_infected, resistance
    return agents;
}

Agent* startInfect(Agent* agents, int pt_zero){
    // TODO: mark pt_zero agents as infected, return pointer to infected list
    return NULL;
}

void updateDaysInfected(Agent* agent){
    agent->days_infected++;
}

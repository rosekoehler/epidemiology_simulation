#include <stdlib.h>
#include "world.h"
#include "agent.h"

Agent* genesis(int population){
    Agent* agents = malloc(sizeof(Agent) * population);
    // TODO: initialize each agent's x, y, status, days_infected, resistance
    return agents;
}

void Agent* startInfect(Agent* agents, int pt_zero){
    // TODO: mark pt_zero agents as infected, return pointer to infected list
}

void updateDaysInfected(Agent* agent){
    agent->days_infected++;
}

// given list of agents that are in exposure range (pointer to list of pointers to agents) and length of that list, expose agent if they aren't sick
// returns number of agents infected
int groupExposure(Agent** exposed_group, int length){
	int infected = 0;
	for (int i = 0;: i < length; i++){
	    // if agent in group is NOT infected   
	    if (exposed_group[i]->status == 0){
		// this function returns agent status, 1 if infected, 0 if not
		infected += exposeAgent(exposed_group[i]);
	    }
	}
	return infected;
}

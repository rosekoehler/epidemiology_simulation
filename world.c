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

int checkDistance(Agent* agent1, Agent* agent2){
    int dx = agent1->x - agent2->x;
    int dy = agent1->y - agent2->y;
    return sqrt(dx * dx + dy * dy);
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

Agent** findExposureGroup(Agent** infected_agents, Agent** all_agents, int population, int length){
	Agent** exposed_agents = malloc(population * sizeof(Agent*));
	int exposed_count = 0;
	for (int i=0; i < length; i++){
		for (int j=0; j<population; j++){
			int dist = checkDistance(infected_agents[i],all_agents[j]);
			if (dist>5  && all_agents[j].status == 0){
				// add to exposed group
				exposed_agents[exposed_count] = &all_agents[j];
				exposed_count++;
			}
		}
	}
	return exposed_agent;
}






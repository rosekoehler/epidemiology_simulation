#include <stdlib.h>
#include "world.h"
#include "agent.h"
#include <math.h>
#include <stdio.h>
Agent* genesis(int population, int width, int height) {
    Agent* agents = malloc(sizeof(Agent) * population);
	if (agents  == NULL) {
        printf("Malloc failed :/ for agent initialization\n");
        return 0;
    }
	for(int i = 0; i<population; i++){
		//set x
		agents[i].x = rand() % width; 
		//set y 
		agents[i].y = rand() % height; 
		//everyone is not infected 
		agents[i].status = 0;
		//days infected = 0 
		agents[i].days_infected = 0; 
		//resitance 
		agents[i].resistance = rand() % 20; 

	}
    // TODO: initialize each agent

    return agents;
}

/*
void startInfect(Agent* agents,Agent** infected_agents, int pt_zero){
    // TODO: mark pt_zero agents as infected
}
*/

int checkDistance(Agent* agent1, Agent* agent2){
    int dx = agent1->x - agent2->x;
    int dy = agent1->y - agent2->y;
    return sqrt(dx * dx + dy * dy);
}


Agent** findExposureGroup(Agent** infected_agents, Agent** all_agents, int population, int length){
	Agent** exposed_agents = malloc(population * sizeof(Agent*));
	int exposed_count = 0;
	for (int i=0; i < length; i++){
		for (int j=0; j<population; j++){
			int dist = checkDistance(infected_agents[i],all_agents[j]);
			if (dist<5  && all_agents[j]->status == 0){
				// add to exposed group
				exposed_agents[exposed_count] = all_agents[j];
				exposed_count++;
			}
		}
	}
	return exposed_agents;
}

// given list of agents that are in exposure range (pointer to list of pointers to agents) and length of that list, expose agent if they aren't sick
// returns number of agents infected
int groupExposure(Agent** exposed_group, int length){
        int infected = 0;
        for (int i = 0; i < length; i++){
            // if agent in group is NOT infected   
            if (exposed_group[i]->status == 0){
                // this function returns agent status, 1 if infected, 0 if not <-commeneted out bc expose isntw ritten yet 
              //  infected += expose(exposed_group[i]);
            }
        }
        return infected;
}




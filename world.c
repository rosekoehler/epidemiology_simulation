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


void startInfect(Agent* agents, int pt_zero){
	for(int i = 0; i<pt_zero; i++){
		agents[i].status = 1;
	}
}

int checkDistance(Agent* agent1, Agent* agent2){
    int dx = agent1->x - agent2->x;
    int dy = agent1->y - agent2->y;
    return sqrt(dx * dx + dy * dy);
}

// Realistically this function should be in agent.c becuase it only acts on a single agent
// returns 1 if agent was infected, 0 if agent didn't get sick
int makeInfected(Agent *exposed){
    if (rand() % 20 > exposed->resistance){
        exposed->status = 1;
        exposed->days_infected = 1;
        return 1;
    }
    return 0;
}


int findExposedGroup(Agent** infected_agents, Agent* all_agents, int population, int infected_count){
	//Agent** exposed_agents = malloc(population * sizeof(Agent*));
	// just including both counts so we can see how much of the exposed group is getting sick
	int exposed_count = 0;
	int new_sickies = 0;
	for (int i=0; i < infected_count; i++){
		for (int j=0; j<population; j++){
			int dist = checkDistance(infected_agents[i],&all_agents[j]);
			if (dist != 0 && dist < 20  && all_agents[j].status == 0){
				// for an not sick agent that is within 20 of a sickie, try to infect them 
				int infect_result = makeInfected(&all_agents[j]);
				exposed_count ++;
				new_sickies += infect_result;
			}
		}
	}
	printf("exposed count: %d, of exposed how many got sick: %d\n", exposed_count, new_sickies); 
	return new_sickies + infected_count;
}

// creates and returns list of currently infected agents
Agent** getSickies(Agent* agents, int pop, int infected_count){
	Agent** infected_agents = malloc(pop * sizeof(Agent*));
	int count = 0;
	for(int i = 0; i<pop && count<infected_count; i++){
		if(agents[i].status == 1){
			infected_agents[count] = &agents[i];
			count++;
			}
	}
	return infected_agents; 

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


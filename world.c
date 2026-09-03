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

int makeInfected(Agent** exposed, int exposed_count){
    int count = 0; 
    for(int i = 0; i< exposed_count; i++){
        if (exposed[i]->status == 0){
	  	if(rand() % 20 >exposed[i]->resistance){
			exposed[i]->status = 1;
			count++;
		} else {
			exposed[i]->resistance++; 
		}
     	}
    }
    printf("MakeInfected(): of %d exposed agents, %d were infected\n",exposed_count,count);	
    return count;
}

int findExposedGroup(Agent** infected_agents, Agent* all_agents, int population, int sickness){
	Agent** exposed_agents = malloc(population * sizeof(Agent*));
	int exposed_count = 0;
	for (int i=0; i < sickness; i++){
		for (int j=0; j<population; j++){
			int dist = checkDistance(infected_agents[i],&all_agents[j]);
			if (dist != 0 && dist < 30  && all_agents[j].status == 0){
				// add to exposed group
				exposed_agents[exposed_count] = &all_agents[j];
				exposed_count++;
			}
		}
	}
	//puts actual number of exposed in. 
	exposed_count = makeInfected(exposed_agents,exposed_count); 
	return exposed_count + sickness;
}


Agent** getSickies(Agent** exposed_agents, Agent* agents, int pop, int infected_count){
	int count = 0;
	//Agent** exposed_agents = malloc(infected_count * sizeof(Agent*));

	for(int i = 0; i<pop && count<=infected_count; i++){
		if(agents[i].status == 1){
			exposed_agents[count] = &agents[i];
			count++;

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


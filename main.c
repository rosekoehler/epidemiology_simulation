#include <stdio.h>
#include <stdlib.h>
#include "agent.h"
#include "world.h"
void printlist(Agent *agent, int pop){
	for(int i = 0; i< pop; i++){
		printf("Agent %d status: %d\n", i, agent[i].status);
	}
}
int main(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);

    // Check we got enough arguments before using them
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <population> <pt_zeros> <days>\n", argv[0]);
        return 1;
    }

    int POPULATION = atoi(argv[1]);
    int PT_ZEROS   = atoi(argv[2]);
    int TIME       = atoi(argv[3]);
	int HEIGHT = 100;
	int  WIDTH = 100;
    // Build all agents
    Agent *all_agents = genesis(POPULATION, WIDTH, HEIGHT);
	
//	printlist(all_agents, POPULATION);	


    Agent **infected_agents = malloc(POPULATION * sizeof(Agent *));
    startInfect(all_agents,PT_ZEROS);
    int infected_count = PT_ZEROS;
printlist(all_agents, POPULATION);  
    // Game loop
    for (int day = 0; day < TIME; day++) {
		// move everybody
		move_agent(all_agents,POPULATION, WIDTH, HEIGHT);
		printf("Below moe agent\n");
		// calculate distance between sick and not sick, see who is getting exposed
		int exposed_count = 0;
		Agent** exposed_agents = malloc(infected_count * sizeof(Agent*));
		exposed_agents = getSickies(exposed_agents, all_agents, POPULATION, infected_count);	
		printf("Below get sickies\n");
		infected_count = findExposedGroup(infected_agents,all_agents, POPULATION,infected_count);
		printf("Below findexpised group agent\n");
		// of the exposed group, update who gets sick
		//infected_count = groupExposure(exposed_agents,exposed_count);
		printf("Day %d: Total infected: %d", day, infected_count);
    }

    // TODO:  write output data here

    free(all_agents);
    return 0;
}

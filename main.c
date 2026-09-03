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
	
    Agent **infected_agents = malloc(POPULATION * sizeof(Agent *));
    startInfect(all_agents,PT_ZEROS);
    int infected_count = PT_ZEROS;
    printlist(all_agents, POPULATION);  
    // Game loop
    for (int day = 1; day <= TIME; day++) {
		// move everybody
		move_agent(all_agents,POPULATION, WIDTH, HEIGHT);
		// figure out who is currently sick
		infected_agents = getSickies(all_agents, POPULATION, infected_count);	
		// findExposedGroup()
		// 	loop through the currently infected agents and see who they are close to
		//	try to infect agents if they are close to the sickies
		infected_count = findExposedGroup(infected_agents,all_agents, POPULATION,infected_count);
		printf("Day %d: Total infected: %d\n", day, infected_count);
    //		free(infected_agents);
    }
	
    // TODO:  write output data here
    printf("\n#############	STATS	############\n\n");
    printf("Population: %d\n", POPULATION);
    printf("Starting infected population: %d\n", PT_ZEROS);
    printf("After %d days, %d people out of %d are now infected\n\n",TIME,infected_count,POPULATION);
    free(all_agents);
    return 0;
}

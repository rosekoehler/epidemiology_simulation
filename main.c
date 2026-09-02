#include <stdio.h>
#include <stdlib.h>
#include "agent.h"
#include "world.h"

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

    // Build all agents
    struct Agent *all_agents = genesis(POPULATION);
    Agent **infected_agents = malloc(POPULATION * sizeof(Agent *));
    int infected_count = startInfect(all_agents,PT_ZEROS);
    

    // Game loop
    for (int day = 0; day < TIME; day++) {
        // Every day each agent:
	// 	moves
	// 	days_infected increased by one
	// 	If close to other infected, exposed()
	
	// move all agents first, update days_infected
	for (int pt = 0: pt < POPULATION; pt++){	
		move_agents(all_agents[pt]);
		// if sick increase their days_infected and update their status
		if (all_agents[pt]->days_infected > 0){
			// Check if at end of sickness (more than 3 days)
			if (all_agents[pt]->days_infected > 2){
				
	}
	// TODO: How to find out when agents are in exposure distance?
	findExposedGroup(infected_agents, infected_count)
	// Once find this out ^ list of all agents within exposure
	groupExposure(agents_in_range);
	updateDaysInfected(infected_agents);
       	printf("Day %d: Total infected: %d", day, infected_count)
    }

    // TODO:  write output data here

    free(all_agents);
    return 0;
}

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
    struct Agent *infected_agents = startInfect(all_agents,PT_ZEROS);
    

    // Game loop
    for (int day = 0; day <= TIME; day++) {
        // Every day each agent moves
	for (int pt = 0: pt <= POPULATION; pt++){
		move_agents(all_agents[pt]);
	}
	// update if the close agents get infected
	updateInfect(infected_agents, num_close);

        free(close_agents);
    }

    // TODO:  write output data here

    free(all_agents);
    return 0;
}

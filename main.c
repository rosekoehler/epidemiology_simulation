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
    int infected_count = startInfect(infected_agents,all_agents,PT_ZEROS);
    

    // Game loop
    for (int day = 0; day < TIME; day++) {
	// move everybody
	move_agents(all_agents,POPULATION, WIDTH, HEIGHT);
	// calculate distance between sick and not sick, see who is getting exposed
	int exposed_count = 0;
	Agent** exposed_agents = findExposedGroup(infected_agents,all_agents, population, infected_count, exposed_count);
	// of the exposed group, update who gets sick
	int new_infected = groupExposure(exposed_agents,exposed_count);
       	infected_count += new_infected
	printf("Day %d: Total infected: %d", day, infected_count)
    }

    // TODO:  write output data here

    free(all_agents);
    return 0;
}

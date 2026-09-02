#include <stdlib.h>
#include "agent.h"

int get_x(Agent *agent){
    return agent->x;
}

int get_y(Agent *agent){
    return agent->y;
}

void move(Agent *agent){
    // TODO: kylie movement logic
}

int exposeAgent(Agent *agent){
    int min = 1;
    int max = 10;
    int ranged_random = (rand() % (max - min + 1)) + min;

    if (ranged_random > agent->resistance){
        agent->status = 1;
        agent->days_infected = 1;
   } else {
        agent->resistance++;
    }
    return agent->status;
}


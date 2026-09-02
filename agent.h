#ifndef agent_h
#define agent_h

#include <stdlib.h>

typedef struct {
    int x;
    int y;
    // 0: default, 1: infected
    int status;
    int days_infected;
    int resistance;
} Agent;

int get_x(Agent *agent);
int get_y(Agent *agent);
void move(Agent *agent);

// returns status like an exit code, run when within exposure distance of another agent.
static inline int expose(Agent *agent){
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

#endif

#ifndef agent_h
#define agent_h

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
void move(Agent *agent[], int pop, int width, int height);

// returns status, run when within exposure distance of another agent.
int expose(Agent *agent);

#endif

#ifndef agent_h
#define agent_h

typedef struct Agent{
    int x;
    int y;
    // 0: default, 1: infected
    int status;
    int days_infected;
    int resistance;
} Agent;

int get_x(Agent *agent);
int get_y(Agent *agent);
int move_agent(Agent *agent, int pop, int width, int height);
#endif

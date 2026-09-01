#ifndef agent_h
#define agent_h

typedef struct {
	int x;
	int y;
	// 1,2,3
	int status;
	int days_infected;
	int resistance;	
}Agent;

int get_x(struct Agent *agent);

int get_y(struct Agent *agent);

void move(struct Agent *agent);

// returns status 
int expose(struct Agent *agent);

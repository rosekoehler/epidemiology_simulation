#include <stdlib.h>
#include "agent.h"
int get_x(Agent *agent){
    return agent->x;
}

int get_y(Agent *agent){
    return agent->y;
}

int  move_agent(Agent *agent, int pop, int width, int height){
	int maxmove = 20; 	

	for(int i = 0; i < pop; i++){
		int move_amount = rand() % maxmove; 
		if (move_amount % 4 == 0){
			agent[i].x+=move_amount; 
		}
		else if (move_amount % 4 == 1){
			agent[i].y+=move_amount; 
		}
		else if (move_amount % 4 == 2){
			agent[i].x-=move_amount; 
		}	
		else if (move_amount % 4 == 3){
			agent[i].y-=move_amount; 
		}
		//check bounds 
		if(agent[i].x > width ){
			agent[i].x = width; 
		}
		else if(agent[i].x < 0){
			agent[i].x = 0; 
		}

		if(agent[i].y > height ){
			agent[i].y = height; 
		}
		if(agent[i].y < 0 ){
			agent[i].y = 0; 
		}	
	}
	return 0; 	
}


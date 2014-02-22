#ifndef AGENT_HPP
#define AGENT_HPP
#include "structs.hpp"

class Agent {
protected:
	AgentType type_;
	static int agentsNumber_;
	int id_;
public:
	Agent(AgentType type) : type_(type){
		id_ = ++ Agent::agentsNumber_;
	}
	int getId(){
		return id_;
	};
	void setId(int id){
		id_ = id;
	};
	static int getAgentsNumber(){
		return agentsNumber_;
	};
	static void setAgentsNumber(int number){
		agentsNumber_ = number;
	};
	virtual void act() = 0;
};
#endif
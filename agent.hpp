#ifndef AGENT_HPP
#define AGENT_HPP
#include "structs.hpp"

class Agent {
protected:
	AgentType type_;
public:
	Agent(AgentType type) : type_(type){}
	virtual void act() = 0;
};
#endif
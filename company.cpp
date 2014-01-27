#include "application.hpp"
Company::Company() : Agent(COMPANY) {}
Company::Company(string name) : Agent(COMPANY) {
	name_ = name;
}
Company::~Company(){}

bool Company::addSkill(int skillId){
	// check if it's already there !
	skills_.push_back(skillId);
	return true;
}

void Company::act(){
	// TODO
}
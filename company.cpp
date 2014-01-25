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


string Company::toString(){
	stringstream ss;

	ss << "Company  : " << name_ << endl;
	
	// for (int i = 0; i < group_.skills_.size(); ++i){
	// 	ss << "Skill " << group_.skills_[i]->name_<< endl;
		
	// }
	for (int i = 0; i < skills_.size(); ++i){
		ss << "Skill " << Application::getSkills().at(skills_[i]).name_ << endl;
		
	}
	return ss.str();
}

void Company::act(){
	// TODO
}
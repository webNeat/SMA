#include "application.hpp"
#include "company.hpp"
Company::Company(){}
Company::Company(string name){
	name_ = name;
}
Company::~Company(){}

string Company::getName(){
	return name_;
}
void Company::setName(string name){
	name_ = name;
}

bool Company::addSkill(int skillId){
	// check if it's already there !
	skills_.push_back(skillId);
	return true;
}
vector<int>& Company::getSkills(){
	return skills_;
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
#include "company.hpp"
Company::Company(){}
// Company::Company(string name, vector<Level> levels){
// 	this->name_ = name;
// 	this->levels_ = levels;
// }
string Company::getName(){
	return name_;
}
void Company::setName(string name){
	name_ = name;
}

void Company::addGroupSkills(SkillGroup& groupe){
	group_ = groupe;
}
SkillGroup& Company::getGroup(){
	return group_;
}
// void Company::addLevel(Level l){
// 	levels_.push_back(l);
// }
// vector<Level>& Company::getLevels(){
// 	return levels_;
// }

string Company::toString(){
	stringstream ss;

	ss << "Company  : " << name_ << endl;
	ss << "Groupe Skills : " << group_.name_ << endl;
	
	// for (int i = 0; i < group_.skills_.size(); ++i){
	// 	ss << "Skill " << group_.skills_[i]->name_<< endl;
		
	// }
	for (int i = 0; i < group_.skills_.size(); ++i){
		ss << "Skill " << [group_.skills_[i]].name_<< endl;
		
	}
	return ss.str();
}

Company::Company(string name){
	name_ = name;
}
Company::~Company(){

}
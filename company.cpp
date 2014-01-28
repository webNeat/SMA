#include "application.hpp"
Company::Company() : Agent(COMPANY), position_(0,0) {}
Company::Company(string name, int x, int y) : Agent(COMPANY), position_(x, y) {
	name_ = name;
	employeesNumber_ = 100;
	hiredEmployeesNumber_ = 0;
	retiredEmployeesNumber_ = 0;
	averageInternshipsNumber_ = 15;
	averageEmployeesNumber_ = 100;
	averageHiredLauriasNumber_ = 20;
	beginGivingInternships_ = 11;
	endGivingInternships_ = 3;
}

Company::~Company(){}

bool Company::addSkill(int skillId){
	// check if it's already there !
	skills_.push_back(skillId);
	return true;
}

void Company::act(){
	int internshipId;
	if(World::getMonth() == beginGivingInternships_){
		for (int i = 0; i < averageInternshipsNumber_; i++){
			internshipId = World::addInternship(id_);
			internshipsIds_.push_back(internshipId);
			Internship& internship = World::getInternship(internshipId);
			for(int j = 0; j < skills_.size(); j++){
				internship.addSkill(skills_.at(j));
			}
		}
	}

	if(World::getMonth() == endGivingInternships_){
		for(vector<int>::iterator index = internshipsIds_.begin(); index != internshipsIds_.end(); index ++ ){
			World::getInternship(*index).setAvailable(false);
		}
	}
}
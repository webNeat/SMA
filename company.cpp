#include "application.hpp"
Company::Company() : Agent(COMPANY), position_(0,0) {}
Company::Company(string name, int x, int y, double ia, double ie, double la, double le, int begin, int end, int n) : Agent(COMPANY), position_(x, y) {
	name_ = name;
	averageInternshipsNumber_ = ia;
	internshipsNumberEcart_ = ie;
	averageHiredLauriasNumber_ = la;
	hiredLaureatsNumberEcart_ = le;
	beginGivingInternships_ = begin;
	endGivingInternships_ = end;
	skillsPerInternship_ = n;
}

Company::~Company(){}

int Company::getAvailableInternship(vector<int>& studentSkills){
	for(int i = 0; i < internshipsIds_.size(); i++){
		Internship& in = World::getInternships().at(internshipsIds_.at(i));
		if(in.getAvailable()){
			if(Application::bernoulli_.get(in.getSkillsPercentage(studentSkills)))
				return internshipsIds_.at(i);
		}
	}
	return -1;
}

bool Company::addSkill(int skillId){
	// check if it's already there !
	skills_.push_back(skillId);
	return true;
}

void Company::act(){
	int internshipId;
	if(World::getMonth() == beginGivingInternships_){
		int number = Application::normale_.get(averageInternshipsNumber_, internshipsNumberEcart_);
		for (int i = 0; i < number; i++){
			internshipId = World::addInternship(id_);
			internshipsIds_.push_back(internshipId);
			Internship& internship = World::getInternship(internshipId);
			int size = skills_.size();
			for(int j = 0; j < skillsPerInternship_; j++){
				internship.addSkill(Application::uniforme_.get(0, size - 1));
			}
		}
	}

	if(World::getMonth() == endGivingInternships_){
		for(vector<int>::iterator index = internshipsIds_.begin(); index != internshipsIds_.end(); index ++ ){
			World::getInternship(*index).setAvailable(false);
		}
	}
}

void Company::print(){
	int available = 0;
	vector<int>::iterator it = internshipsIds_.begin();
	while(it != internshipsIds_.end()){
		if(World::getInternships().at(*it).getAvailable())
			available ++;
		it ++;
	}
	cout << name_ << endl;
	cout << "\tTotal:" << internshipsIds_.size() << endl; 
	cout << "\tAvailable:" << available << endl;
}
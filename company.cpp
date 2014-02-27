#include "application.hpp"
Company::Company() : Agent(COMPANY), position_(0,0) {}
Company::Company(string name, int x, int y, double ia, double ie, int begin, int end, int n) : Agent(COMPANY), position_(x, y) {
	name_ = name;
	averageInternshipsNumber_ = ia;
	internshipsNumberEcart_ = ie;
	beginGivingInternships_ = begin;
	endGivingInternships_ = end;
	skillsPerInternship_ = n;
}

Company::~Company(){}

double Company::getSkillsPercentage(vector<int>& laureatSkills){
	double found = 0;
	vector<int>::iterator it = laureatSkills.begin();
	while(it != laureatSkills.end()){
		vector<int>::iterator pos = find(skills_.begin(), skills_.end(), *it);
		if(pos != skills_.end())
			found ++; 
		it ++;
	}
	return found / (double) skills_.size();
}

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
	// TODO check if it's already there !
	skills_.push_back(skillId);
	return true;
}

bool Company::willHire(vector<int>& laureatSkills){
	vector<int>::iterator it = laureatSkills.begin(),
		pos;
	while(it != laureatSkills.end()){
		pos = find(skills_.begin(), skills_.end(), *it);
		if(pos != skills_.end() && Application::bernoulli_.get(getSkillsPercentage(laureatSkills)))
			return true;
		it ++;
	}
	return false;
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
	// print();
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
	// cout << "\tTotal:" << internshipsIds_.size() << endl; 
	// cout << "\tAvailable:" << available << endl;
	cout << "\tTotal Laureats:" << World::getLaureats().size() << endl;
	cout << "\tHired:" << laureatIds_.size() << endl;
}

int Company::getAvailableInternships(){
	int number = 0;
	vector<int>::iterator it = internshipsIds_.begin();
	while(it != internshipsIds_.end()){
		if(World::getInternship(*it).getAvailable())
			number ++;
		it ++;
	}
	return number;
}
int Company::getHiredStudents(){
	int number = 0;
	vector<int>::iterator it = internshipsIds_.begin();
	while(it != internshipsIds_.end()){
		if(World::getInternship(*it).getStudentId() != -1)
			number ++;
		it ++;
	}
	return number;
}
#include "school.hpp"

School::School(string name, double average, double ecart, int x, int y) 
	: Agent(SCHOOL), name_(name), position_(x,y), studentsArrivingNumber_(average, ecart) {}
School::~School(){}



int School::addLevel(double successPercentage, bool hasInternship, double internshipDuration, int internshipStart, int internshipEnd){
	Level level(successPercentage, hasInternship, internshipDuration, internshipStart, internshipEnd);
	levels_.push_back(level);
	int id = levels_.size() - 1;
	levels_.at(id).setId(id);
	return id;
}
Level& School::getLevel(int levelId){
	return levels_.at(levelId);
}

bool School::addSkillToLevel(int skillId, int levelId){
	if(levelId >= levels_.size())
		return false;
	getLevel(levelId).addSkill(skillId);
	return true;
}

void School::addStudent(int id){
	// studentIds_.push_back(id);
}

string School::toString(){
	stringstream ss;

	ss << "name :" << name_ << " position : (" << position_.getX() << "," << position_.getY() << ")" << endl;
	for (int i = 0; i < levels_.size(); ++i)
	{
		ss << levels_[i].toString();
	}
	return ss.str();
}

void School::act(){
	// TODO
}

void School::print(){
	
}
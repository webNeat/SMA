#include "school.hpp"

School::School(string name, double average, double ecart, int x, int y) 
	: Agent(SCHOOL), name_(name), position_(x,y), studentsArrivingNumber_(average, ecart) {}
School::~School(){}

void School::setId(int id){
	id_ = id;
}

int School::getId(){
	return id_;
}

string School::getName(){
	return name_;
}
void School::setName(string name){
	name_ = name;
}

Point& School::getPosition(){
	return position_;
}

int School::addLevel(int studentNumber, double successPercentage, bool hasInternship, double internshipDuration, int internshipStart, int internshipEnd){
	Level level(studentNumber, successPercentage, hasInternship, internshipDuration, internshipStart, internshipEnd);
	levels_.push_back(level);
	int id = levels_.size() - 1;
	levels_.at(id).setId(id);
	return id;
}
Level& School::getLevel(int levelId){
	return levels_.at(levelId);
}
vector<Level>& School::getLevels(){
	return levels_;
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
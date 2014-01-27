#include "world.hpp"

School::School(string name, double average, double ecart, int x, int y) 
	: Agent(SCHOOL), name_(name), position_(x,y) {}
School::~School(){}


int School::addLevel(double successPercentage, bool hasInternship, double internshipDuration, int internshipStart){
	Level level(successPercentage, hasInternship, internshipDuration, internshipStart);
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

void School::addStudentToLevel(int studentId, int levelId){
	getLevel(levelId).addStudent(studentId);
}
void School::removeStudentFromLevel(int studentId, int levelId){
	getLevel(levelId).removeStudent(studentId);
}

void School::generateStudents(){
	// int number = studentsArrivingNumber_.get();
	int number = 10;
	for(int i = 0; i < number; i++){
		int studentId = World::addStudent(id_, 0);
		addStudentToLevel(studentId, 0);
	}
}

void School::act(){
	// TODO
}

void School::print(){
	
}
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

void School::deliberate(){
	Level& last = levels_.back();
	vector<int>& students = last.getstudentIds();
	for(vector<int>::iterator it = students.begin(); it != students.end(); it ++ ){
		World::addLaureat(id_);
	}
	students.clear();
	int size = levels_.size();
	for(int i = size - 2; i > -1; i -- ){
		Level& level = levels_.at(i);
		Level& nextLevel = levels_.at(i + 1);
		vector<int>& students = level.getstudentIds();
		int number = level.getSuccessPercentage() * students.size();
		for(int j = 0; j < number; j++){
			int id = students.front();
			nextLevel.addStudent(id);
			students.erase(students.begin());
			World::getStudent(id).setLevelId(World::getStudent(id).getLevelId() + 1);
		}
	}
}

void School::act(){
	// TODO : should be improved !
	if(World::getMonth() == 9){
		deliberate();
		generateStudents();
	}
}

void School::print(){
	
}
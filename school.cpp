#include "application.hpp"

School::School(string name, double average, double ecart, int x, int y) 
	: Agent(SCHOOL), name_(name), position_(x,y)
	{
		arrivingStudentsAverage_ = average;
		arrivingStudentsEcart_ = ecart;
	}

School::~School(){}

int School::addLevel(double successPercentage, bool hasInternship, double internshipDuration, int internshipStart){
	Level level(successPercentage, hasInternship, internshipDuration, internshipStart);
	levels_.push_back(level);
	int id = levels_.size() - 1;
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
	int number = Application::normale_.get(arrivingStudentsAverage_, arrivingStudentsEcart_);
	for(int i = 0; i < number; i++){
		int studentId = World::addStudent(id_, 0);
		addStudentToLevel(studentId, 0);
	}
}

void School::deliberate(){
	Level& last = levels_.back();
	vector<int> students = last.getStudentIds();
	last.getStudentIds().clear();
	int size = levels_.size();
	for(int i = size - 2; i > -1; i -- ){
		Level& level = levels_.at(i);
		Level& nextLevel = levels_.at(i + 1);
		vector<int>& studentsTemp = level.getStudentIds();
		int number = studentsTemp.size();
		for(int j = 0; j < number; j++){
			int id = studentsTemp.front();
			bool condition = Application::bernoulli_.get(level.getSuccessPercentage());
				// && ( ! level.getHasInternship() ||  World::getStudent(id).getCurrentInternshipId() != -1);
			if(condition){
				nextLevel.addStudent(id);
				World::getStudent(id).setLevelId(World::getStudent(id).getLevelId() + 1);
			}else{
				level.addStudent(id);
			}
			studentsTemp.erase(studentsTemp.begin());
		}
	}
	int number = students.size();
	for(int i = 0; i < number; i++ ){
		int id = students.at(i);
		bool condition = Application::bernoulli_.get(last.getSuccessPercentage());
				// && ( ! last.getHasInternship() ||  World::getStudent(id).getCurrentInternshipId() != -1);
		if(condition){
			addLaureat(World::addLaureat(id));
			World::removeStudent(id);
		}else{
			last.addStudent(id);
		}
	}
}

void School::act(){
	if(World::getMonth() == 9){
		World::initStudents();
		deliberate();
		generateStudents();
		// print();
	}
}

void School::print(){
	int i = 0;
	int levelsNumber = levels_.size();
	cout << name_ << ":" << endl;
	while(i < levelsNumber){
		cout << "\t" << i << ": " << levels_.at(i).getStudentIds().size() << endl;
		i++;
	}
	cout << "\tLaureats: " << laureatIds_.size() << endl;
}

int School::getWorkingLaureats(){
	int working = 0;
	for(vector<int>::iterator it = laureatIds_.begin(); it != laureatIds_.end(); it ++)
		if(World::getLaureat(*it).getCurrentCompanyId() != -1)
			working ++;
	return working;
}

int School::getStudentsHavingInternship(){
	int having = 0;
	for(vector<Level>::iterator it = levels_.begin(); it != levels_.end(); it ++)
		for(vector<int>::iterator itt = it->getStudentIds().begin(); itt != it->getStudentIds().end(); itt ++)
			if(World::getStudent(*itt).getCurrentInternshipId() != -1)
				having ++;
	return having;
}

int School::studentsShouldHaveInternship(){
	int number = 0;
	for(vector<Level>::iterator it = levels_.begin(); it != levels_.end(); it ++)
		if(it->getHasInternship())
			number += it->getStudentIds().size();
	return number;
}
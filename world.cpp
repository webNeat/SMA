#include "application.hpp"
#include "world.hpp"

map<int, Company> World::companies_;
map<int, School> World::schools_;
map<int, Student> World::students_;
map<int, Laureat> World::laureats_;
vector<Internship> World::internships_;
int World::month_ = 9;

int World::addSchool(string name, double average, double ecart, int x, int y, int key){
	// check if there is no school with the same name !
	School school(name, average, ecart, x, y);
	if(key == -1)
		key = school.getId();
	else
		school.setId(key);
	schools_.insert(pair<int, School>(key ,school));
	return key;
}

void World::initStudents(){
	for(map<int, Student>::iterator it = students_.begin(); it != students_.end(); it ++){
		it->second.setCurrentInternshipId(-1);
	}
}

int World::addStudent(int schoolId, int levelId, int key){
	School& school = getSchool(schoolId);
	Student student(schoolId, levelId, school.getPosition().getX(), school.getPosition().getY());
	if(key == -1)
		key = student.getId();
	else
		student.setId(key);
	students_.insert(pair<int, Student>(key, student));
	return key;
}

int World::addStudentToSchool(int schoolId){
	School& school = getSchool(schoolId);
	Student student(schoolId, 0, school.getPosition().getX(), school.getPosition().getY());
	int id = student.getId();
	students_.insert(pair<int, Student>(id ,student));
	schools_.at(schoolId).addStudentToLevel(id, 0);
	return id;
}

void World::removeStudent(int id){
	students_.erase(id);
}

int World::addLaureat(int studentId, int key){
	if(studentId != -1){
		Laureat laureat(getStudent(studentId));
		if(key == -1)
			key = laureat.getId();
		else
			laureat.setId(key);
		laureats_.insert(pair<int, Laureat>(key ,laureat));
		return key;
	}else{
		Laureat laureat;
		if(key == -1)
			key = laureat.getId();
		else
			laureat.setId(key);
		laureats_.insert(pair<int, Laureat>(key ,laureat));
		return key;
	}
}
int World::addInternship(int companyId){
	Internship internship(companyId);
	internships_.push_back(internship);
	int id = internships_.size() - 1;
	return id;
}
void World::clear(){
	students_.clear();
	internships_.clear();
	laureats_.clear();
	companies_.clear();
	schools_.clear();
}
School& World::getSchool(int schoolId){
	return schools_.at(schoolId);
}
Student& World::getStudent(int studentId){
	return students_.at(studentId);
}

Laureat& World::getLaureat(int schoolId){
	return laureats_.at(schoolId);
}
Internship& World::getInternship(int comapnyId){
	return internships_.at(comapnyId);
}

int World::addCompany(string name, int x, int y, int key){
	Company company(name, x, y);
	if(key == -1)
		key = company.getId();
	else
		company.setId(key);
	companies_.insert(pair<int, Company> (key, company));
	return key;
}

Company& World::getCompany(int companyId){
	return companies_.at(companyId);
}

int World::getCompanyNearTo(int x, int y){
	int cx, cy;
	map<int, Company>::iterator it = companies_.begin();
	double radius = Application::getParam("companyRadius");
	while(it != companies_.end()){
		cx = it->second.getPosition().getX();
		cy = it->second.getPosition().getY();
		if( ( x > cx - radius ) && ( x < cx + radius ) && ( y > cy - radius ) && ( y < cy + radius ))
			return it->first;
		it ++;
	}
	return -1;
}

void World::randomAct(vector<Agent *>& agents){
	Agent * temp;
	int last = agents.size() - 1;
	while(last > 0){
		int index = Application::uniforme_.get(0, last);
		agents.at(index)->act();
		temp = agents.at(index);
		agents.at(index) = agents.at(last);
		agents.at(last) = temp;
		last --;
	}
	agents.at(0)->act();
}

void World::act(){
	vector<Agent *> agents;
	// Schools
	for(map<int, School>::iterator it = schools_.begin(); it != schools_.end(); it ++)
		agents.push_back(&(it->second));
	randomAct(agents);

	agents.clear();
	// Add companies
	for(map<int, Company>::iterator it = companies_.begin(); it != companies_.end(); it ++)
		agents.push_back(&(it->second));
	// Add students
	for(map<int, Student>::iterator it = students_.begin(); it != students_.end(); it ++)
		agents.push_back(&(it->second));
	// Add laureats
	for(map<int, Laureat>::iterator it = laureats_.begin(); it != laureats_.end(); it ++)
		agents.push_back(&(it->second));
	randomAct(agents);

	month_ ++;
	if(month_ == 13)
		month_ = 1;
}

double World::getWorkingLaureats(){
	int working = 0;
	for(map<int, Company>::iterator it = companies_.begin(); it != companies_.end(); it ++)
		working += it->second.getLaureatIds().size();
	return working;
}

double World::getStudentsHavingInternship(){
	int having = 0;
	for(map<int, Student>::iterator it = students_.begin(); it != students_.end(); it ++){
		if(it->second.getCurrentInternshipId() != -1)
			having ++;
	}
	return having;
}

int World::studentsShouldHaveInternship(){
	int number = 0;
	for(map<int, School>::iterator it = schools_.begin(); it != schools_.end(); it ++){
		for(vector<Level>::iterator itt = it->second.getLevels().begin(); itt != it->second.getLevels().end(); itt ++)
			if(itt->getHasInternship())
				number += itt->getStudentIds().size();
	}
	return number;	
}
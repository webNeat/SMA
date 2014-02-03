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
	// agents_.push_back(&(schools_.at(key)));
	return key;
}

int World::addStudent(int schoolId, int levelId, int key){
	// cout <<  "addStudent: schoolId: " << schoolId << " | levelId: " << levelId << " | key: " << key << endl;
	Student student(schoolId, levelId);
	if(key == -1)
		key = student.getId();
	else
		student.setId(key);
	students_.insert(pair<int, Student>(key, student));
	return key;
}

int World::addStudentToSchool(int schoolId){
	Student student(schoolId);
	int id = student.getId();
	students_.insert(pair<int, Student>(id ,student));
	// agents_.push_back(&(students_.at(id)));
	schools_.at(schoolId).addStudentToLevel(id, 0);
	return id;
}

void World::removeStudent(int id){
	students_.erase(id);
};

int World::addLaureat(int schoolId, int key){
	Laureat laureat(schoolId);
	if(key == -1)
		key = laureat.getId();
	else
		laureat.setId(key);
	laureats_.insert(pair<int, Laureat>(key ,laureat));
	return key;
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
	// agents_.push_back(&(companies_.at(key)));
	return key;
}

Company& World::getCompany(int companyId){
	// if(companyId < companies_.size())
	return companies_.at(companyId);
}

void World::act(){
	// TODO : The order should be random !!
	map<int, Company>::iterator itCompanies = companies_.begin();
	while(itCompanies != companies_.end()){
		itCompanies->second.act();
		itCompanies ++;
	}
	
	map<int, School>::iterator itSchools = schools_.begin();
	while(itSchools != schools_.end()){
		itSchools->second.act();
		itSchools ++;
	}
	
	map<int, Student>::iterator itStudents = students_.begin();
	while(itStudents != students_.end()){
		itStudents->second.act();
		itStudents ++;
	}
	
	map<int, Laureat>::iterator itLaureats = laureats_.begin();
	while(itLaureats != laureats_.end()){
		itLaureats->second.act();
		itLaureats ++;
	}

	month_ ++;
	if(month_ == 13)
		month_ = 1;
}
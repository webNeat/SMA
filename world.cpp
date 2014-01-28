#include "application.hpp"
#include "world.hpp"

vector<Company> World::companies_;
vector<School> World::schools_;
vector<Student> World::students_;
vector<Laureat> World::laureats_;
vector<Internship> World::internships_;
int World::month_ = 9;

int World::addSchool(string name, double average, double ecart, int x, int y){
	// check if there is no school with the same name !
	School school(name, average, ecart, x, y);
	schools_.push_back(school);
	int id = schools_.size() - 1;
	schools_.at(id).setId(id);
	// agents_.push_back(&(schools_.at(id)));
	return id;
}

int World::addStudent(int schoolId, int levelId){
	Student student(schoolId, levelId);
	students_.push_back(student);
	int id = students_.size() - 1;
	return id;
}

int World::addLaureat(int schoolId){
	Laureat laureat(schoolId);
	laureats_.push_back(laureat);
	int id = laureats_.size() - 1;
	return id;
}
int World::addInternship(int companyId){
	Internship internship(companyId);
	internships_.push_back(internship);
	int id = internships_.size() - 1;
	return id;
}
void World::clear(){
	companies_.clear();
	schools_.clear();
}
School& World::getSchool(int schoolId){
	// if(schoolId < schools_.size())
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

int World::addStudentToSchool(int schoolId){
	Student student(schoolId);
	students_.push_back(student);
	int id = students_.size() - 1;
	// agents_.push_back(&(students_.at(id)));
	schools_.at(schoolId).addStudentToLevel(id, 0);
	return id;
}

int World::addCompany(string name, int x, int y){
	Company company(name, x, y);
	companies_.push_back(company);
	int id = companies_.size() - 1;
	// agents_.push_back(&(companies_.at(id)));
	companies_.at(id).setId(id);
	return id;
}

Company& World::getCompany(int companyId){
	// if(companyId < companies_.size())
	return companies_.at(companyId);
}

void World::act(){
	// TODO : The order should be random !!
	vector<Company>::iterator itCompanies = companies_.begin();
	while(itCompanies != companies_.end()){
		itCompanies->act();
		itCompanies ++;
	}
	
	vector<School>::iterator itSchools = schools_.begin();
	while(itSchools != schools_.end()){
		itSchools->act();
		itSchools ++;
	}
	
	vector<Student>::iterator itStudents = students_.begin();
	while(itStudents != students_.end()){
		itStudents->act();
		itStudents ++;
	}
	
	vector<Laureat>::iterator itLaureats = laureats_.begin();
	while(itLaureats != laureats_.end()){
		itLaureats->act();
		itLaureats ++;
	}

	month_ ++;
	if(month_ == 13)
		month_ = 1;
}
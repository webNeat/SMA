#ifndef WORLD_HPP
#define WORLD_HPP
#include "company.hpp"
#include "school.hpp"
#include "student.hpp"
#include "laureat.hpp"
#include "internship.hpp"
#include "lib.hpp"
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;
/**
 * Add vector<Positions> and direction for Students and Laureats
 * Add move method for Student and Laureat
 * 	Parametres: distance by movement; number of movements by month
 * 	Add bool new for Company (true when created; false from the first act)
 * 	struct Agent { Type, id }
 */
class World {
private:
	static vector<Agent *> agents_;
	static map<int, Company> companies_;
	static map<int, School> schools_;
	static map<int, Student> students_;
	static map<int, Laureat> laureats_;
	static vector<Internship> internships_;
	static int month_;
public:	
	static int addSchool(string, double = 90, double = 10, int = 0, int = 0, int = -1);
	static School& getSchool(int);
	static void initStudents();
	static int addStudentToSchool(int);
	static int addStudent(int, int, int = -1);
	static void removeStudent(int);
	static int addLaureat(int, int = -1);
	static int addInternship(int);
	
	static Student& getStudent(int);
	static Laureat& getLaureat(int);
	static Internship& getInternship(int);
	
	static int addCompany(string name, int = 0, int = 0, int = -1);
	static Company& getCompany(int);
	static int getCompanyNearTo(int, int);
	static void clear();
	static void act();

	static int getMonth(){
		return month_;
	};
	static void setMonth(int month){
		month_ = month;
	}
	static vector<Internship>& getInternships(){
		return internships_;
	};
	static map<int, Company>& getCompanies(){
		return companies_;
	};
	static map<int, School>& getSchools(){
		return schools_;
	};
	static map<int, Laureat>& getLaureats(){
		return laureats_;
	};
	static map<int, Student>& getStudents(){
		return students_;
	};

	static void  setInternships(vector<Internship> interenships){
		 internships_ = interenships;
	};
	static void  setCompanies(map<int, Company> companies){
		 companies_ = companies;
	};
	static void  setSchools(map<int, School> schools){
		 schools_ = schools;
	};
	static void  setLaureats(map<int, Laureat> laureats){
		 laureats_ = laureats;
	};
	static void setStudents(map<int, Student> students){
		 students_ = students;
	};
	
};
#endif
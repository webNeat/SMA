#ifndef WORLD_HPP
#define WORLD_HPP
#include "company.hpp"
#include "school.hpp"
#include "student.hpp"
#include "laureat.hpp"
#include "internship.hpp"
#include "lib.hpp"
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
class World {
private:
	static vector<Agent *> agents_;
	static vector<Company> companies_;
	static vector<School> schools_;
	static vector<Student> students_;
	static vector<Laureat> laureats_;
	static vector<Internship> internships_;
	static int month_;
public:	
	static int addSchool(string, int = 0, int = 0);
	static School& getSchool(int);
	static void addStudentToSchool(int);
	static int addCompany(string name);
	static Company& getCompany(int);
	static string toString();
	static void save();
	static void load();	
	static void clear();
	static void act();
};
#endif
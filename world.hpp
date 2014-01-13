#ifndef WORLD_HPP
#define WORLD_HPP
#include "company.hpp"
#include "school.hpp"
#include <vector>
#include <sstream>
#include "lib.hpp"
#include <fstream>
using namespace std;
class World {
private:
	static vector<Company> companies_;
	static vector<School> schools_;
public:	
	static int addSchool(string, int = 0, int = 0);
	static School& getSchool(int);
	static int addCompany(string name);
	static Company& getCompany(int);
	static string toString();
	static void save();
	static void load();	
	static void clear();
};
#endif
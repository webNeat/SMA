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
	vector<Company> companies_;
	vector<School> schools_;
public:	
	int addSchool(string, int = 0, int = 0);
	School& getSchool(int);

	int addCompany(string name);
	Company& getCompany(int);
	//World(const World &s);
	//World& operator=(const World &s); 

	World();
	~World();
	string toString();
	void save();
	void load();	
};
#endif
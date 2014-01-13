#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "structs.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include "lib.hpp"
#include "world.hpp"
using namespace std;

class Application {
private:
	static World currentWorld_;
	static vector<Skill> skills_;
	static map<string, SkillGroup> skillGroups_;
	static map<string, double> params_;
public:
	static void addParam(string key, double value);
 	static map<string, double>& getParams();
	static void saveParams();
	static void loadParams();
	
	static int addSkill(string name);
	static const vector<Skill>& getSkills();
	static Skill& getSkill(int);
	static void saveSkills();
	static void loadSkills();

 	static bool addSkillGroup(string name); 
 	// returns false if group already exists
 	static bool addSkillToGroup(int, string);
 	// return false if no group with the given name
	static void saveGroupSkills();
	static void loadGroupSkills();
 	
 	static void addWorld(World& world);
	static void saveWorld();
	static void loadWorld();

	static void init();
	static void run();
 	static string toString();
};
#endif
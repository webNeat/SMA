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
	static vector<Skill> skills_;
	static vector<SkillGroup> skillsGroups_;
	static map<string,double> params_;
	static World currentWorld_;
	// Interface interface_;
	// EventHandler event_;
public:
	static void addParams(string key, double value);
	static int addSkill(Skill& l);
 	static SkillGroup& makeSkillGroup(string name);
 	static void addSkillToGroup(int, SkillGroup& groupe);
 	static map<string, double>& getParams();
 	static void addWorld(World& world);
 	static string toString();
	static void init();
	static void run();
	static void saveParams();
	static void loadParams();
	static void saveSkills();
	static void loadSkills();
	static void saveGroupSkills();
	static void loadGroupSkills();
	static vector<Skill>& getSkills();
	static void saveWorld();
	static void loadWorld();
};
#endif
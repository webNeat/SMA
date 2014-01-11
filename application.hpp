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
		vector<Skill> skills_;
		vector<SkillGroup> skillsGroups_;
		map<string,double> params_;
		World currentWorld_;
		// Interface interface_;
		// EventHandler event_;
	 public:
	 	Application();
		void addParams(string key, double value);
		int addSkill(Skill& l);
	 	SkillGroup& makeSkillGroup(string name);
	 	void addSkillToGroup(int, SkillGroup& groupe);
	 	map<string, double>& getParams();
	 	void addWorld(World& world);
	 	string toString();
		void init();
		void run();
		void saveParams();
		void loadParams();
		void saveSkills();
		void loadSkills();
		void saveGroupSkills();
		void loadGroupSkills();
		
};
#endif
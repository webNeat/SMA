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
#include "generators.hpp"
using namespace std;

class Application {
private:
	static vector<Skill> skills_;
	static map<string, vector<int> > skillGroups_;
	static map<string, double> params_;

public:
	static Uniforme uniforme_;
	static Bernoulli bernoulli_;
	static Normale normale_;

	static void addParam(string key, double value);
 	static map<string, double>& getParams(){
 		return params_;
 	};
 	static double getParam(string name){
 		return params_.at(name);
 	}
 	static void setParams(map<string, double>& p){
 		params_ = p;
 	};
	static void printParams();
	
	static int addSkill(string name);
	static vector<Skill>& getSkills(){
		return skills_;
	};
	static void setSkills(vector<Skill>& s){
		skills_ = s;
	}
	static Skill& getSkill(int);

	static map<string, vector<int> >& getSkillGroups(){
		return skillGroups_;
	}
	static void setSkillGroups(map<string, vector<int> >& sg){
		skillGroups_ = sg;
	}
 	static bool addSkillGroup(string name); 
 	// returns false if group already exists
 	static bool addSkillToGroup(int, string);
 	// return false if no group with the given name
 	static void printSkills();
};
#endif
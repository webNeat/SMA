#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <string>
#include <vector>
using namespace std;

typedef struct {
		string name_;
	}Skill;


typedef struct {
		string name_;
		vector<int> skills_; 
	}SkillGroup;

#endif
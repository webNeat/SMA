#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "structs.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Level {
private:
	int id_;
	int studentNumber_;
	SkillGroup skillGroup_;
	double successPercentage_;
	bool hasInternship_;
	double internshipDuration_;
	int internshipStart_;
	int internshipEnd_;
public:
 	Level();
 	Level(int, int, double, bool, double, int, int);
 	~Level();

	int getId();
	int getstudentNumber();
	SkillGroup& getSkillGroup();
	double getSuccessPercentage();
	bool getHasInternship();
	double getInternshipDuration();
	int getInternshipStart();
	int getInternshipEnd();
	string toString();

	void addSkill(int);
	//string toString(ostream& out);
// 	Level(const Level &l);
// 	Level& operator=(const Level&l);	
};

//ostream& operator<<(ostream& o, Level &l);
#endif
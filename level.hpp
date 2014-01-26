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
	double successPercentage_;
	bool hasInternship_;
	double internshipDuration_;
	int internshipStart_;
	int internshipEnd_;
	vector<int> skills_;
	vector<int> studentIds_;
public:
 	Level();
 	Level(double, bool, double, int, int);
 	~Level();

	int getId();
	void setId(int);
	int getstudentNumber();
	vector<int>& getSkills();
	vector<int>& getstudentIds();
	double getSuccessPercentage();
	bool getHasInternship();
	double getInternshipDuration();
	int getInternshipStart();
	int getInternshipEnd();
	string toString();

	void addSkill(int);
	void addStudent(int);
	//string toString(ostream& out);
// 	Level(const Level &l);
// 	Level& operator=(const Level&l);	
};

//ostream& operator<<(ostream& o, Level &l);
#endif
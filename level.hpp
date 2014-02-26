#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "structs.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Level {
private:
	double successPercentage_;
	bool hasInternship_;
	double internshipDuration_;
	int internshipStart_;
	vector<int> skills_;
	vector<int> studentIds_;
public:
 	Level();
 	Level(double, bool, double, int);
 	~Level();

	int getstudentNumber();
	vector<int>& getSkills();
	void setSkills(vector<int> list){
		skills_ = list;
	}
	vector<int>& getStudentIds();
	void setStudentIds(vector<int> list){
		studentIds_ = list;
	}
	double getSuccessPercentage();
	bool getHasInternship();
	double getInternshipDuration();
	int getInternshipStart();
	string toString();

	void addSkill(int);
	void addStudent(int);
	void removeStudent(int);
	//string toString(ostream& out);
// 	Level(const Level &l);
// 	Level& operator=(const Level&l);	
};

//ostream& operator<<(ostream& o, Level &l);
#endif
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

		int getId();
		int getstudentNumber();
		SkillGroup& getSkillGroup();
		double getSuccessPercentage();
		bool getHasInternship();
		double getInternshipDuration();
		int getInternshipStart();
		int getInternshipEnd();
		string toString();
		//string toString(ostream& out);
	 	Level();
	 	Level(int, int, SkillGroup, double, bool, double, int, int);
	 	~Level();
	// 	Level(const Level &l);
	// 	Level& operator=(const Level&l);

	
};
//ostream& operator<<(ostream& o, Level &l);
#endif
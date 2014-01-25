#ifndef SCHOOL_HPP
#define SCHOOL_HPP
#include "level.hpp"
#include "agent.hpp"
#include "point.hpp"
#include "generators.hpp"
#include <string>
#include <vector>
using namespace std;
class School : Agent {
private:
	int id_;
	string name_;
	Point position_;
	vector<Level> levels_;
	vector<int> laureatIds_;
	// parametres de simulations
	Normale studentsArrivingNumber_;
public:
 	School();
 	School(string name, double, double, int = 0, int = 0);
	~School();
	
	int getId(){
		return id_;
	};

 	string getName(){
 		return name_;
 	};

	Point& getPosition(){
		return position_;
	};
	vector<Level>& getLevels(){
		return levels_;
	};
	vector<int>& getLaureatIds(){
		return laureatIds_;
	};

	
	int addLevel(int, double, bool, double, int, int);
	Level& getLevel(int);
	bool addSkillToLevel(int, int);

	void addStudent(int);

 	string toString();
 	void act();
 	void print();
};
#endif
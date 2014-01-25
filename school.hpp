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

	void setId(int);
	int getId();
 	string getName();
 	void setName(string name);

	Point& getPosition();
	
	int addLevel(int, double, bool, double, int, int);
	vector<Level>& getLevels();
	Level& getLevel(int);
	bool addSkillToLevel(int, int);

	void addStudent(int);

 	string toString();
 	void act();
 	void print();
};
#endif
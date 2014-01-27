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
	void setId(int id){
		id_ = id;
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

	
	int addLevel( double, bool, double, int);
	Level& getLevel(int);
	bool addSkillToLevel(int, int);

	void addStudentToLevel(int, int);
	void removeStudentFromLevel(int, int);
	void generateStudents();

 	string toString();
 	void act();
 	void print();
};
#endif
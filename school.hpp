#ifndef SCHOOL_HPP
#define SCHOOL_HPP
#include "level.hpp"
#include "agent.hpp"
#include "point.hpp"
#include "generators.hpp"
#include <string>
#include <vector>
using namespace std;
class School : public Agent {
private:
	string name_;
	Point position_;
	vector<Level> levels_;
	vector<int> laureatIds_;
	// parametres de simulations
	double arrivingStudentsAverage_;
	double arrivingStudentsEcart_;
public:
 	School(string name, double, double, int = 0, int = 0);
	~School();
 	string getName(){
 		return name_;
 	}
	Point& getPosition(){
		return position_;
	}
	vector<Level>& getLevels(){
		return levels_;
	}
	vector<int>& getLaureatIds(){
		return laureatIds_;
	}
	void setLaureatIds(vector<int> list){
		laureatIds_ = list;
	}
	double getAverage(){
		return arrivingStudentsAverage_;
	}
	double getEcart(){
		return arrivingStudentsEcart_;
	}
	
	int addLevel( double, bool, double, int);
	Level& getLevel(int);
	bool addSkillToLevel(int, int);

	void addStudentToLevel(int, int);
	void removeStudentFromLevel(int, int);
	void generateStudents();

	void addLaureat(int id){
		laureatIds_.push_back(id);
	}

	void deliberate();
 	void act();
 	void print();
};
#endif
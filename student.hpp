#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <vector>
#include "agent.hpp"
#include "point.hpp"
using namespace std;

class Student : public Agent {
private:
	int schoolId_;
	int levelId_;
	vector<int> skills_;
	vector<int> internships_;
	int currentIntershipId_;
	Point currentPosition_;
	vector<Point> positions_;
	double angle_;
public:
	Student(int, int = 0, int = 0, int = 0);

	int getSchoolId(){
		return schoolId_;
	};
	int getLevelId(){
		return levelId_;
	};
	void setLevelId(int newId){
		levelId_ = newId;
	};
	vector<int>& getSkills(){
		return skills_;
	};
	vector<int>& getInternShips(){
		return internships_;
	};
	int getCurrenInternshipId(){
		return currentIntershipId_;
	};
	void setCurrenInternshipId(int currentID){
		currentIntershipId_ = currentID;
	};
	Point& getCurrentPosition(){
		return currentPosition_;
	}
	vector<Point>& getPositions(){
		return positions_;
	}
	double getAngle(){
		return angle_;
	}
	void setAngle(double angle){
		angle_ = angle;
	}
	void act();
};
#endif
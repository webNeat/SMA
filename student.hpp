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
	void setSkills(vector<int> list){
		skills_ = list;
	}
	vector<int>& getInternships(){
		return internships_;
	};
	void setInternships(vector<int> list){
		internships_ = list;
	}
	int getCurrentInternshipId(){
		return currentIntershipId_;
	};
	void setCurrentInternshipId(int currentID){
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

	void addInternship(int id){
		internships_.push_back(id);
	}
	void addSkills(vector<int>&);
	void act();
};
#endif
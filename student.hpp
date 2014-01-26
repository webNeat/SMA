#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <vector>
#include "agent.hpp"
using namespace std;

class Student : Agent {
private:
	int schoolId_;
	int levelId_;
	vector<int> skills_;
	vector<int> internships_;
	int currentIntershipId_;
public:
	Student(int, int = 0);

	int getSchoolId(){
		return schoolId_;
	};
	int getLevelId(){
		return levelId_;
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

	void act();
};
#endif
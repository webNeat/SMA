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
	void act();
};
#endif
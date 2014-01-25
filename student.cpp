#include "student.hpp"

Student::Student(int schoolId, int levelId): Agent(STUDENT) {
	schoolId_ = schoolId;
	levelId_ = levelId;
	currentIntershipId_ = -1;
	// TODO : add skills depending on the school and level
}

void Student::act(){
	// TODO
}
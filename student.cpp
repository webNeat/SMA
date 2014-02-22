#include <iostream>
#include <cmath>
#include "application.hpp"
Student::Student(int schoolId, int levelId, int x, int y): Agent(STUDENT), currentPosition_(x,y) {
	// cout << "Student Constructed ! id: " << id_ << endl;
	schoolId_ = schoolId;
	levelId_ = levelId;
	currentIntershipId_ = -1;
	angle_ = Application::uniforme_.get(0, 44 / 7);
	// TODO : add skills depending on the school and level
}

void Student::act(){
	positions_.clear();
	Level& level = World::getSchool(schoolId_).getLevels().at(levelId_);
	if(!level.getHasInternship() || currentIntershipId_ != -1)
		return;

	int mapWidth = Application::getParam("mapWidth"),
		mapHeight = Application::getParam("mapHeight"),
		distancePerDay = Application::getParam("distancePerDay"),
		distancePerMonth = 30 * distancePerDay,
		x = currentPosition_.getX(),
		y = currentPosition_.getY(),
		dx, dy, companyId, internshipId, distance = 0;

	positions_.push_back(currentPosition_);
	while(distance < distancePerMonth){
		dx = distancePerDay * cos(angle_);
		dy = distancePerDay * sin(angle_);
		while(x + dx < 0 || x + dx > mapWidth || y + dy < 0 || y + dy > mapHeight) {
			angle_ = Application::uniforme_.get(0, 44 / 7);
			dx = distancePerDay * cos(angle_);
			dy = distancePerDay * sin(angle_);
		}
		x += dx;
		y += dy;
		companyId = World::getCompanyNearTo(x, y);
		if(companyId != -1){
			cout << "company found !" << endl;
			internshipId = World::getCompany(companyId).getAvailableInternship();
			if(internshipId != -1){
				cout << "internship added for student " << id_ << endl;
				currentIntershipId_ = internshipId;
				World::getInternships().at(internshipId).setStudentId(id_);
				break;
			}
		}
		positions_.push_back(Point(x, y));
		distance += distancePerDay;
	}

	currentPosition_.setX(x);
	currentPosition_.setY(y);
}
#include <cmath>
#include "application.hpp"

Laureat::Laureat() : Agent(LAUREAT) {}

Laureat::Laureat(Student& student) : Agent(LAUREAT) {
	schoolId_ = student.getSchoolId();
	currentCompanyId_ = -1;
	skills_ = student.getSkills();
	internships_ = student.getInternships();
	currentPosition_.setX(student.getCurrentPosition().getX());
	currentPosition_.setY(student.getCurrentPosition().getY());
	angle_ = Application::uniforme_.get(0, 44 / 7);
}

void Laureat::act(){
	positions_.clear();
	if(currentCompanyId_ != -1)
		return;

	int mapWidth = Application::getParam("mapWidth"),
		mapHeight = Application::getParam("mapHeight"),
		distancePerDay = Application::getParam("distancePerDay"),
		distancePerMonth = 30 * distancePerDay,
		x = currentPosition_.getX(),
		y = currentPosition_.getY(),
		dx, dy, companyId, distance = 0;

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
		if(companyId != -1 && World::getCompany(companyId).willHire(skills_)){
			currentCompanyId_ = companyId;
			World::getCompany(companyId).addLaureat(id_);
			break;
		}
		positions_.push_back(Point(x, y));
		distance += distancePerDay;
	}

	currentPosition_.setX(x);
	currentPosition_.setY(y);
}
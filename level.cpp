#include <algorithm>
#include "world.hpp"
Level::Level(){

}

Level::Level(
		double successPercentage, 
		bool hasInternship, 
		double internshipDuration, 
		int internshipStart
	){
	this->successPercentage_ =successPercentage;
	this->hasInternship_ = hasInternship;
	this->internshipDuration_ = internshipDuration;
	this->internshipStart_ = internshipStart;
}
Level::~Level(){}

int Level::getstudentNumber(){
	return studentIds_.size();
}
vector<int>& Level::getSkills(){
	return skills_;
}
vector<int>& Level::getStudentIds(){
	return studentIds_;
}
double Level::getSuccessPercentage(){
	return successPercentage_;
}
bool Level::getHasInternship(){
	return hasInternship_;
}
double Level::getInternshipDuration(){
	return internshipDuration_;
}
int Level::getInternshipStart(){
	return internshipStart_;
}

void Level::addSkill(int skillId){
	skills_.push_back(skillId);
}

void Level::addStudent(int studentId){
	Student& student = World::getStudent(studentId);
	student.addSkills(skills_);	
	studentIds_.push_back(studentId);
}

void Level::removeStudent(int studentId){
	vector<int>::iterator it = find(studentIds_.begin(), studentIds_.end(), studentId);
	if(it != studentIds_.end()){
		studentIds_.erase(it);
	}
}
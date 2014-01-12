#include "level.hpp"
Level::Level(){

}

Level::Level(int id, int studentNumber, SkillGroup skillGroup, double successPercentage, bool hasInternship, double internshipDuration, int internshipStart, int internshipEnd){
	cout << "dkhal"<<endl;
	this->id_ = id;
	this->studentNumber_ = studentNumber;
	this->skillGroup_ = skillGroup;
	this->successPercentage_ =successPercentage;
	this->hasInternship_ = hasInternship;
	this->internshipDuration_ = internshipDuration;
	this->internshipStart_ = internshipStart;
	this->internshipEnd_ = internshipEnd;

}
	 
Level::~Level(){

}
int Level::getId(){
	return id_;
}
int Level::getstudentNumber(){
	return studentNumber_;
}
SkillGroup& Level::getSkillGroup(){
	return skillGroup_;
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
int Level::getInternshipEnd(){
	return internshipEnd_;
}


string Level::toString(){
	stringstream ss;
	ss << id_<< " " << studentNumber_ << "" << skillGroup_.name_ << " " << successPercentage_ << " " << hasInternship_ << " " << internshipDuration_ << " " << internshipStart_ << " " << internshipEnd_ << endl;
	return ss.str();
}

// void Level::toString(ostream& out){
// 	out << toString;
// }

// ostream& operator<<(ostream& out, Level &l){
// 	l.toString(out);
// 	return out;
// }
#include "level.hpp"
Level::Level(){

}

Level::Level(int studentNumber, 
		double successPercentage, 
		bool hasInternship, 
		double internshipDuration, 
		int internshipStart, 
		int internshipEnd
	){
	this->successPercentage_ =successPercentage;
	this->hasInternship_ = hasInternship;
	this->internshipDuration_ = internshipDuration;
	this->internshipStart_ = internshipStart;
	this->internshipEnd_ = internshipEnd;
}
Level::~Level(){}

int Level::getId(){
	return id_;
}
void Level::setId(int id){
	id_ = id;
}
int Level::getstudentNumber(){
	return studentIds_.size();
}
vector<int>& Level::getSkills(){
	return skills_;
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
	ss << id_<< " " << studentIds_.size() << " " << successPercentage_ << " " << hasInternship_ << " " << internshipDuration_ << " " << internshipStart_ << " " << internshipEnd_ << endl;
	return ss.str();
}

void Level::addSkill(int skillId){
	skills_.push_back(skillId);
}

void Level::addStudent(int studentId){
	// TODO : needs some checkings
	studentIds_.push_back(studentId);
}

// void Level::toString(ostream& out){
// 	out << toString;
// }

// ostream& operator<<(ostream& out, Level &l){
// 	l.toString(out);
// 	return out;
// }
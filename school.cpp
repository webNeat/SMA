#include "school.hpp"

School::School(){}
School::School(string name, int x, int y){
	Point position(x, y);
	name_ = name;
	position_ = position;
}
School::~School(){}

string School::getName(){
	return name_;
}
void School::setName(string name){
	name_ = name;
}

Point& School::getPosition(){
	return position_;
}

int School::addLevel(int id, int studentNumber, double successPercentage, bool hasInternship, double internshipDuration, int internshipStart, int internshipEnd){
	Level level(id, studentNumber, successPercentage, hasInternship, internshipDuration, internshipStart, internshipEnd);
	levels_.push_back(level);
	return levels_.size() - 1;
}
Level& School::getLevel(int levelId){
	return levels_.at(levelId);
}
vector<Level>& School::getLevels(){
	return levels_;
}
bool School::addSkillToLevel(int skillId, int levelId){
	if(levelId >= levels_.size())
		return false;
	getLevel(levelId).addSkill(skillId);
	return true;
}

string School::toString(){
	stringstream ss;

	ss << "name :" << name_ << " position : (" << position_.getX() << "," << position_.getY() << ")" << endl;
	for (int i = 0; i < levels_.size(); ++i)
	{
		ss << levels_[i].toString();
	}
	return ss.str();
}
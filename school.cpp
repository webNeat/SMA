#include "school.hpp"

School::School(){}

School::School(string name, Point position){
	this->name_ = name;
	this->position_ = position;
}
string School::getName(){
	return name_;
}
void School::setName(string name){
	name_ = name;
}

Point& School::getPosition(){
	return position_;
}

void School::addLevel(Level l){
	levels_.push_back(l);
}
vector<Level>& School::getLevels(){
	return levels_;
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
School::~School(){

}
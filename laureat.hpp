#ifndef Laureat_HPP
#define Laureat_HPP
#include <vector>
#include "world.hpp"
using namespace std;

class Laureat : public Agent {
private:
	int schoolId_;
	vector<int> skills_;
	vector<int> internships_;
	int currentCompanyId_;
	Point currentPosition_;
	vector<Point> positions_;
	double angle_;
public:
	Laureat();
	Laureat(Student&);
	void act();

	int getSchoolId(){
		return schoolId_;
	}
	void setSchoolId(int id){
		schoolId_ = id;
	}
	vector<int>& getSkills(){
		return skills_;
	}
	void setSkills(vector<int> list){
		skills_ = list;
	}
	vector<int>& getInternships(){
		return internships_;
	}
	void setInternships(vector<int> list){
		internships_ = list;
	}
	int getCurrentCompanyId(){
		return currentCompanyId_;
	}
	void setCurrentCompanyId(int compnayId){
		currentCompanyId_ = compnayId;
	}
	Point& getCurrentPosition(){
		return currentPosition_;
	}
	vector<Point>& getPositions(){
		return positions_;
	}
	double getAngle(){
		return angle_;
	}
	void setAngle(double angle){
		angle_ = angle;
	}

};
#endif
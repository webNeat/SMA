#ifndef INTERNSHIP_HPP
#define INTERNSHIP_HPP
#include <vector>
using namespace std;

class Internship {
private:
	int companyId_;
	int studentId_;
	vector<int> skillIds_;
	bool available_;
public:
	Internship(int companyId) : companyId_(companyId), studentId_(-1), available_(true) {};
	void addSkill(int id){
		skillIds_.push_back(id);
	}
	int getCompanyId(){
		return companyId_;
	}
	int getStudentId(){
		return studentId_;
	}
	vector<int>& getSkills(){
		return skillIds_;
	}
	void setStudentId(int studentId){
		studentId_ = studentId;
		available_ = (studentId == -1);
	}
	bool getAvailable(){
		return available_;
	}
	void setAvailable(bool val){
		available_ = val;
	}

	double getSkillsPercentage(vector<int>&);

};
#endif
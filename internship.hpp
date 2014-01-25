#ifndef INTERNSHIP_HPP
#define INTERNSHIP_HPP
#include <vector>
using namespace std;

class Internship {
private:
	int companyId_;
	int studentId_;
	vector<int> skillIds_;
public:
	Internship(int);
	void addSkill(int);
	int getCompanyId(){
		return companyId_;
	};
	int getStudentId(){
		return studentId_;
	};
	vector<int>& getSkills(){
		return skillIds_;
	};

};
#endif
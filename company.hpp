#ifndef COMPANY_HPP
#define COMPANY_HPP
#include "agent.hpp"
#include "point.hpp"
#include "level.hpp"
#include <string>
#include <vector>
using namespace std;

class Company : public Agent {
private:
	string name_;
	Point position_;
	vector<int> skills_;
	vector<int> internshipsIds_;
	vector<int> laureatIds_;
	// Statistiques
	int employeesNumber_;
	int hiredEmployeesNumber_;
	int retiredEmployeesNumber_;
	// Probability parametres
	int averageInternshipsNumber_;
	int averageEmployeesNumber_;
	int averageHiredLauriasNumber_;
	// Other parametres
	int beginGivingInternships_;
	int endGivingInternships_;
public:
 	Company();
 	Company(string name, int = 0, int = 0);
 	~Company();
	
	vector<int>& getSkills(){
		return skills_;
	};
	void setSkills(vector<int> skills){
		skills_ = skills;
	};
		Point& getPosition(){
		return position_;
	};

	vector<int>& getInternshipsIds(){
		return internshipsIds_;
	};
	void setInternshipsIds(vector<int> InternshipsIds){
		internshipsIds_ = InternshipsIds;
	};
	vector<int>& getLaureatIds(){
		return laureatIds_;
	};
	void setLaureatIds(vector<int> laureatIds){
		laureatIds_ = laureatIds;
	};

	int getAverageInternshipsNumber(){
		return averageInternshipsNumber_;
	};
	void setAverageInternshipsNumber(int averageInternshipsNumber){
		averageInternshipsNumber_ = averageInternshipsNumber;
	};

	string getName(){
		return name_;
	};
 	void setName(string name){
 		name_ = name;
 	};

 	int getEmployeesNumber(){
 		return employeesNumber_;
 	};

	void setEmployeesNumber(int employeesNumber){
 		employeesNumber_ = employeesNumber;
 	};
 	
 	int getHiredEmployeesNumber(){
 		return hiredEmployeesNumber_;
 	};
 	void setHiredEmployeesNumber(int hiredEmployeesNumber){
 		hiredEmployeesNumber_ = hiredEmployeesNumber;
 	};
 	int getRetiredEmployeesNumber(){
 		return retiredEmployeesNumber_;
 	};
 	void setRetiredEmployeesNumber(int retiredEmployeesNumber){
 		retiredEmployeesNumber_ = retiredEmployeesNumber;
 	};
 	int getAverageEmployeesNumber(){
 		return averageEmployeesNumber_;
 	};
 	void setAverageEmployeesNumber(int averageEmployeesNumber){
 		averageEmployeesNumber_ = averageEmployeesNumber;
 	};
 	int getAverageHiredLauriasNumber(){
 		return averageHiredLauriasNumber_;
 	};
 	void setAverageHiredLauriasNumber(int averageHiredLauriasNumber){
 		averageHiredLauriasNumber_ = averageHiredLauriasNumber;
 	};
 	int getBeginGivingInternships(){
 		return beginGivingInternships_;
 	};
 	void setBeginGivingInternships(int beginGivingInternships){
 		beginGivingInternships_ = beginGivingInternships;
 	};
 	int getEndGivingInternships(){
 		return endGivingInternships_;
 	};
 	void setEndGivingInternships(int endGivingInternships){
 		endGivingInternships_ = endGivingInternships;
 	};

 	bool addSkill(int);

 	void act();
};
#endif
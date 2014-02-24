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
	int hiredEmployeesNumber_;
	int retiredEmployeesNumber_;
	// Probability parametres
	double averageInternshipsNumber_;
	double internshipsNumberEcart_;
	double averageHiredLauriasNumber_;
	double hiredLaureatsNumberEcart_;
	// Other parametres
	int beginGivingInternships_;
	int endGivingInternships_;
	int skillsPerInternship_;
public:
 	Company();
 	Company(string name,
 		int x = 0,
 		int y = 0,
 		double internshipsNumber = 30,
 		double internshipsEcart = 5,
 		double laureatsNumber = 10,
 		double laureatsEcart = 2,
 		int start = 11,
 		int end = 3,
 		int skillsByInternship = 1);
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

 	int getAvailableInternship(vector<int>&);

 	bool addSkill(int);

 	void act();
 	void print();
};
#endif
#ifndef COMPANY_HPP
#define COMPANY_HPP
#include "agent.hpp"
#include "level.hpp"
#include <string>
#include <vector>
using namespace std;

class Company : Agent {
private:
	int id_;
	string name_;
	vector<int> skills_;
	vector<int> InternshipsIds_;
	vector<int> laureatIds_;
	// Statistiques
	int employeesNumber_;
	int hiredEmployeesNumber_;
	int retiredEmployeesNumber_;
	// Probability parametres
	vector<int> averageInternshipsNumber_;
	int averageEmployeesNumber_;
	int averageHiredLauriasNumber_;
	// Other parametres
	int beginGivingInternships_;
	int endGivingInternships_;
public:
 	Company();
 	Company(string name);
 	~Company();
	
	vector<int>& getSkills(){
		return skills_;
	};
	 void setSkills(vector<int> skills){
		skills_ = skills;
	};
	

	vector<int>& getInternshipsIds(){
		return InternshipsIds_;
	};
	void setInternshipsIds(vector<int> InternshipsIds){
		InternshipsIds_ = InternshipsIds;
	};
	vector<int>& getLaureatIds(){
		return laureatIds_;
	};
	void setLaureatIds(vector<int> laureatIds){
		laureatIds_ = laureatIds;
	};

	vector<int>& getAverageInternshipsNumber(){
		return averageInternshipsNumber_;
	};
	void setAverageInternshipsNumber(vector<int> averageInternshipsNumber){
		averageInternshipsNumber_ = averageInternshipsNumber;
	};

	int getId(){
		return id_;
	};
	void setId(int id){
		id_ = id;
	};

	string getName(){
		return name_;
	};
 	void setName(string name){
 		name_ = name;
 	};

 	int getEmployessNumber(){
 		return employeesNumber_;
 	};

	void setEmployessNumber(int employeesNumber){
 		employeesNumber_ = employeesNumber;
 	};
 	
 	int getIHiredEmployeesNumber(){
 		return hiredEmployeesNumber_;
 	};
 	void setIHiredEmployeesNumber(int hiredEmployeesNumber){
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
 
 	
 	string toString();
 	void act();
 //	Company(string name, vector<Level> levels);

	//vector<Level>& getLevels();
// 	void setLevels(vector<Level> levels);
// 	Company(const Company &s);
// 	Company& operator=(const Company &s); 
};
#endif
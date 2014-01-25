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
	
	void setId(int);
	int getId();

	string getName();
 	void setName(string name);

 	bool addSkill(int);
 	vector<int>& getSkills();
 	
 	string toString();
 	void act();
 //	Company(string name, vector<Level> levels);

	//vector<Level>& getLevels();
// 	void setLevels(vector<Level> levels);
// 	Company(const Company &s);
// 	Company& operator=(const Company &s); 
};
#endif
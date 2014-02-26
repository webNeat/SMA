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
	// Probability parametres
	double averageInternshipsNumber_;
	double internshipsNumberEcart_;
	// Other parametres
	int beginGivingInternships_;
	int endGivingInternships_;
	int skillsPerInternship_;

	double getSkillsPercentage(vector<int>& );
public:
 	Company();
 	Company(string name,
 		int x = 0,
 		int y = 0,
 		double internshipsNumber = 30,
 		double internshipsEcart = 5,
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
	int getSkillsPerInternship(){
		return skillsPerInternship_;
	}
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
	}
	int getInternshipsNumberEcart(){
		return internshipsNumberEcart_;
	}
	void setInternshipsNumber(double average, double ecart){
		averageInternshipsNumber_ = average;
		internshipsNumberEcart_ = ecart; 
	}

	string getName(){
		return name_;
	};
 	void setName(string name){
 		name_ = name;
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
 	void addLaureat(int id){
 		laureatIds_.push_back(id);
 	}
 	bool willHire(vector<int>&);

 	void act();
 	void print();
};
#endif
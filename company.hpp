#ifndef COMPANY_HPP
#define COMPANY_HPP
#include "level.hpp"
#include <string>
#include <vector>
using namespace std;
class Company {
private:
	string name_;
	vector<int> skills_;
	//vector<Level> levels_;
public:
 	Company();
 	Company(string name);
 	~Company();
	
	string getName();
 	void setName(string name);

 	bool addSkill(int);
 	vector<int>& getSkills();
 	
 	string toString();
 //	Company(string name, vector<Level> levels);

	//vector<Level>& getLevels();
// 	void setLevels(vector<Level> levels);
// 	Company(const Company &s);
// 	Company& operator=(const Company &s); 
};
#endif
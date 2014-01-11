#ifndef COMPANY_HPP
#define COMPANY_HPP
#include "level.hpp"
#include <string>
#include <vector>
using namespace std;
class Company {
	
	private:
		string name_;
		SkillGroup group_;
		//vector<Level> levels_;
	public:
		string getName();
	 	void setName(string name);
	 	SkillGroup& getGroup();
	 	//void addLevel(Level l);
	 	void addGroupSkills(SkillGroup& groupe);
	 	string toString();
	 	Company();
	 //	Company(string name, vector<Level> levels);
	 	Company(string name);

	 	~Company();
		//vector<Level>& getLevels();
	// 	void setLevels(vector<Level> levels);
	// 	Company(const Company &s);
	// 	Company& operator=(const Company &s); 

		

	
};
#endif
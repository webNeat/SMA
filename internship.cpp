#include "world.hpp"

double Internship::getSkillsPercentage(vector<int>& studentSkills){
	double found = 0;
	vector<int>::iterator it = studentSkills.begin();
	while(it != studentSkills.end()){
		vector<int>::iterator pos = find(skillIds_.begin(), skillIds_.end(), *it);
		if(pos != skillIds_.end())
			found ++; 
		it ++;
	}
	return found / (double) skillIds_.size();
}
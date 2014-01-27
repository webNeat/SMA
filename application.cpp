#include "file.hpp"
#include "application.hpp"

map<string,double> Application::params_;
vector<Skill> Application::skills_;
map<string, vector<int> > Application::skillGroups_;
Uniforme Application::uniforme;
Bernoulli Application::bernoulli;

void Application::addParam(string key, double value){
	params_.insert(pair<string, double>(key,value));
}

int Application::addSkill(string name){
	Skill skill;
	skill.name = name;
	skills_.push_back(skill);
	return skills_.size() - 1;
}

Skill& Application::getSkill(int skillId){
	// check if it exists !!
	return skills_.at(skillId);
}

bool Application::addSkillGroup(string name){
	if(skillGroups_.find(name) != skillGroups_.end()){
		return false;
	}
	vector<int> vi;
	skillGroups_.insert(pair<string, vector<int> >(name, vi));
	return true;
}

bool Application::addSkillToGroup(int skillId, string groupName){
	map<string, vector<int> >::iterator it = skillGroups_.find(groupName);
	bool success = false;
	if(it != skillGroups_.end()){
		it->second.push_back(skillId);
		success = true;
	}
	return success;
}

void Application::printParams(){
	map<string, double>::iterator it = params_.begin();
	while(it != params_.end()){
		cout << "\t" << it->first << " : " << it->second << endl;
		it++;
	}
}

void Application::printSkills(){
	vector<Skill>::iterator sIt = skills_.begin();
	cout << "Skills:" << endl;
	while(sIt != skills_.end()){
		cout << "\t" << sIt->name << endl;
		sIt ++;
	}

	map<string, vector<int> >::iterator gIt = skillGroups_.begin();
	cout << "Groups:" << endl;
	while(gIt != skillGroups_.end()){
		cout << "\t" << gIt->first << endl;
		vector<int>::iterator it = gIt->second.begin();
		while(it != gIt->second.end()){
			cout << "\t\t" << getSkill(*it).name << endl;
			it ++;
		}
		gIt ++;
	}
}

void Application::act(){
	World::act();
	File::saveWorld();
}
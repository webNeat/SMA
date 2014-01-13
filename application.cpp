#include "application.hpp"

map<string,double> Application::params_;
vector<Skill> Application::skills_;
map<string, SkillGroup> Application::skillGroups_;

void Application::addParam(string key, double value){
	params_.insert(pair<string, double>(key,value));
}

map<string, double>& Application::getParams(){
	return params_;
}

void Application::saveParams(){
	ofstream f;
	f.open("files/params.sdb");
	if(f){
		f << params_.size() << endl;
		for (map<string,double>::iterator it = params_.begin(); it != params_.end(); ++it){
			string s = it -> first;
			f << strReplace(s,' ', '#') << " " << it->second << endl;
		}
		f.close();
	}else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}
}

void Application::loadParams(){
	ifstream f;
	string key;
	double value;
	int taille;
	f.open("files/params.sdb");
	if(f){
		f >> taille;
		for (int i = 0; i < taille; ++i){
			f >> key;
			strReplace(key,'#', ' ');
			f >> value;
			addParam(key, value);
		}
		f.close();
	}else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;

	}
}

int Application::addSkill(string name){
	Skill skill;
	skill.name_ = name;
	skills_.push_back(skill);
	return skills_.size() - 1;
}

const vector<Skill>& Application::getSkills(){
	return skills_;
}

Skill& Application::getSkill(int skillId){
	// check if it exists !!
	return skills_.at(skillId);
}

void Application::saveSkills(){
	ofstream f;
	f.open("files/skills.sdb");
	if(f){
		for (int i = 0; i < skills_.size(); ++i){
			f << skills_.at(i).name_ << endl;
		}
		f.close();
	}else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}
}

void Application::loadSkills(){
	ifstream f;
	string s;
	Skill skill;

	f.open("files/skills.sdb");
	if(f){
		getline(f,s);
		while(!f.eof()){
			skill.name_ = s;
			skills_.push_back(skill);
			getline(f,s);
		}
		f.close();
	}else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}
}


bool Application::addSkillGroup(string name){
	SkillGroup group;
	group.name_  = name;
	if(skillGroups_.find(name) != skillGroups_.end()){
		return false;
	}
	skillGroups_.insert(pair<string, SkillGroup>(name, group));
	return true;
}

bool Application::addSkillToGroup(int skillId, string groupName){
	map<string, SkillGroup>::iterator it = skillGroups_.find(groupName);
	bool success = false;
	if(it != skillGroups_.end()){
		it->second.skills_.push_back(skillId);
		success = true;
	}
	return success;
}

void Application::saveGroupSkills(){
	ofstream f;
	f.open("files/groupskills.sdb");
	if(f){
		f << skillGroups_.size() << endl;
		map<string, SkillGroup>::iterator groupsIt = skillGroups_.begin();
		vector<int>::iterator skillsIt;
		while(groupsIt != skillGroups_.end()){
			f << strReplace(groupsIt->second.name_, ' ', '#') << " "
			  << groupsIt->second.skills_.size();
			skillsIt = groupsIt->second.skills_.begin();
			while(skillsIt != groupsIt->second.skills_.end()){
				f << " " << (* skillsIt);
				skillsIt ++;
			}
			f << endl;
			groupsIt ++;
		}
		f.close();
	}else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}
}

void Application::loadGroupSkills(){
	ifstream f;
	int tailleG, tailleS;
	string nameG;
	int id;
	f.open("files/groupskills.sdb");
	if(f){
		f >> tailleG;
		for (int i = 0; i < tailleG; ++i){
			f >> nameG;
			f >> strReplace(nameG, '#', ' ');
			addSkillGroup(nameG);
			f >> tailleS;
			for (int j = 0; j < tailleS; ++j){
				f >> id;
				addSkillToGroup(id, nameG); 
			}
		}
		f.close();
	}else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}
}



void Application::init(){
	loadParams();
	loadSkills();
	loadGroupSkills();
	World::load();
}

string Application::toString(){
	stringstream ss;
	ss << "Application :" << endl;
	ss << "Skills :" << endl;
	for (int i = 0; i < skills_.size(); ++i){
		ss << "skill name: " << skills_[i].name_ << endl;
	}
	ss << "Group Skills : " << endl;

	map<string, SkillGroup>::iterator groupsIt = skillGroups_.begin();
	vector<int>::iterator skillsIt;
	while(groupsIt != skillGroups_.end()){
		ss <<  "Group name : " << groupsIt->first << endl;
		skillsIt = groupsIt->second.skills_.begin();
		while(skillsIt != groupsIt->second.skills_.end()){
			ss << "\tSKILL name : " << skills_.at(* skillsIt).name_ << endl;
			skillsIt ++;
		}
		groupsIt ++;
	}

	ss << "Params Configuration :" << endl;
	for (map<string, double>::iterator it = params_.begin(); it!= params_.end(); ++it){
		ss << it->first << " => " << it->second << endl;
	}
	ss << World::toString();
	return ss.str();
}
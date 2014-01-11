#include "application.hpp"

vector<Skill> Application::skills_;
vector<SkillGroup> Application::skillsGroups_;
map<string,double> Application::params_;
World Application::currentWorld_;

void Application::addParams(string key, double value){
	params_.insert(pair<string, double>(key,value));
}
int Application::addSkill(Skill& l){
	skills_.push_back(l);
	return skills_.size()-1;
}
SkillGroup& Application::makeSkillGroup(string name){
	SkillGroup group;
	group.name_  = name;
	skillsGroups_.push_back(group);
	return skillsGroups_.back();
}


void Application::addSkillToGroup(int id, SkillGroup& groupe){

	groupe.skills_.push_back(id);
}
map<string, double>& Application::getParams(){
	return params_;
}
void Application::addWorld(World& world){
	currentWorld_ = world;
}
string Application::toString(){
	stringstream ss;
	ss << "Application :" << endl;
	ss << "Skills :" << endl;
	for (int i = 0; i < skills_.size(); ++i)
	{
		ss << "skill name: " << skills_[i].name_ << endl;
	}
	ss << "Group Skills : " << endl;
	for (int i = 0; i < skillsGroups_.size(); ++i)
	{
		ss << "Group name : " << skillsGroups_[i].name_<< endl;
		for (int j = 0; j < skillsGroups_[i].skills_.size(); ++j)
		{
			ss << "\t Skill name : " << skills_[skillsGroups_[i].skills_[j]].name_<< endl;
			
		}
	}
	ss << "Params Configuration :" << endl;
	for (map<string, double>::iterator it = params_.begin(); it!= params_.end(); ++it){
		ss << it->first << " => " << it->second << endl;
	}
	ss << currentWorld_.toString();

	return ss.str();
}

void Application::init(){
	/*Remplir Params Configuration*/
	for (int i = 0; i < 10; ++i){
		stringstream ss;
		ss << "succes pourcentage " << i;
		//params_.insert(pair<string, double>(,(i*2.0)/1.5));
		addParams(ss.str(), (i*2.0)/1.5);
	}
		
	/*Remplir SKILLS*/
	Skill skill1,skill2,skill3,skill4;
	
	skill1.name_ = "C++";
	skill2.name_ = "Java";
	skill3.name_ = "PHP";
	skill4.name_ = "Biologie";

	int id1 = addSkill(skill1);
	int id2 = addSkill(skill2);
	int id3= addSkill(skill3);
	int id4 = addSkill(skill4);


	
	/*Remplir Group SKILLS*/


	SkillGroup& group1 = makeSkillGroup("Informatique");
	addSkillToGroup(id1,group1);
	addSkillToGroup(id2,group1);
	addSkillToGroup(id3,group1);
	
	// group1.name_ = "Informatique";
	// group1.skills_.push_back();
	// group1.skills_.push_back(&skills_.at(id2));
	// group1.skills_.push_back(&skills_.at(id3));
	
	//skillsGroups_.push_back(group1);

	SkillGroup& group2 = makeSkillGroup("Medcine");
	addSkillToGroup(id4,group2);

	// SkillGroup group2;
	// group2.name_ = "Medcine";
	// group2.skills_.push_back(&skills_.at(id4));
	//skillsGroups_.push_back(group2);

}

void Application::saveSkills(){
	ofstream f;
	f.open("files/skills.sdb");
	if(f){
		for (int i = 0; i < skills_.size(); ++i)
		{
			f << skills_.at(i).name_ << endl;
		}
		f.close();

	}	
	else{
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
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;

	}

}



void Application::saveParams(){
	ofstream f;
	f.open("files/params.sdb");
	if(f){
		f << params_.size() << endl;
		for (map<string,double>::iterator it = params_.begin(); it != params_.end(); ++it)
		{
			string s = it -> first;
			f << strReplace(s,' ', '#') << " " << it->second << endl;
		}
		f.close();

	}	
	else{
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
		for (int i = 0; i < taille; ++i)
		{
			f >> key;
			strReplace(key,'#', ' ');
			f >> value;
			addParams(key, value);
		}
		f.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;

	}


}

void Application::saveGroupSkills(){
	ofstream f;
	f.open("files/groupskills.sdb");
	if(f){
		int tailleG = skillsGroups_.size();
		f << tailleG << endl;
		for (int i = 0; i < tailleG; ++i)
		{
			f << strReplace(skillsGroups_.at(i).name_, ' ', '#') << " ";
			int tailleS = skillsGroups_.at(i).skills_.size();
			f << tailleS << " ";
			for (int j = 0; j < tailleS ; ++j)
			{
				f << skillsGroups_.at(i).skills_.at(j) << " ";
			}
			f << endl;

		}
		f.close();

	}	
	else{
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
		for (int i = 0; i < tailleG; ++i)
		{
			f >> nameG;
			f >> strReplace(nameG, '#', ' ');
			SkillGroup& group = makeSkillGroup(nameG);
			f >> tailleS;
			for (int j = 0; j < tailleS; ++j)
			{
				f >> id;
				addSkillToGroup(id, group); 
			}
		}
		f.close();

	}
	else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}	

}

vector<Skill>& Application::getSkills(){
	return skills_;
}

void Application::saveWorld(){
	currentWorld_.save();
}

void Application::loadWorld(){
	currentWorld_.load();
}
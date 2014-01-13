#include "application.hpp"
#include "world.hpp"

World::World(){}

World::~World(){}

int World::addSchool(string name, int x, int y){
	// check if there is no school with the same name !
	School school(name, x, y);
	schools_.push_back(school);
	return schools_.size() - 1;
}

School& World::getSchool(int schoolId){
	// if(schoolId < schools_.size())
	return schools_.at(schoolId);
}

int World::addCompany(string name){
	Company company(name);
	companies_.push_back(company);
	return companies_.size() - 1;
}

Company& World::getCompany(int companyId){
	// if(companyId < companies_.size())
	return companies_.at(companyId);
}

string World::toString(){
	stringstream ss;
	ss << "WORLD : " << endl;
	ss << "Companies : " << endl;
	for (int i = 0; i < companies_.size(); ++i)
	{
		ss << companies_[i].toString();
	}
	ss << endl;
	ss << "Schhols : " << endl;	
	for (int i = 0; i < schools_.size(); ++i)
	{
		ss << schools_[i].toString();
	}
	return ss.str();

}

void World::save(){
	ofstream f;
	int tailleC, tailleS, tailleGC, tailleLvelS, tailleSGL;
	
	f.open("files/world.sdb");
	if(f){
		/*Writing Companies*/
		tailleC =  companies_.size();
		f << tailleC << endl;
		for (int i = 0; i < tailleC; ++i){
			string s = companies_.at(i).getName();
			f << strReplace(s,' ','#') << " ";
			tailleGC = companies_.at(i).getSkills().size();
			f << tailleGC << " " ;
			for (int j = 0; j < tailleGC; ++j){
				f << companies_.at(i).getSkills().at(j) << " ";
			}
			f << endl;
		}
		/*Writing Schools*/
		string nameGL; 
		tailleS = schools_.size();
		f << tailleS << endl;
		for (int i = 0; i < tailleS; ++i)
		{
			string s = schools_.at(i).getName();
			f << strReplace(s, ' ', '#') << " ";
			f << schools_.at(i).getPosition().getX() << " " << schools_.at(i).getPosition().getY() << " ";
			tailleLvelS = schools_.at(i).getLevels().size();
			f << tailleLvelS << " ";
			 for (int j = 0; j < tailleLvelS; ++j)
			 {
			 	f << schools_.at(i).getLevels().at(j).getId() << " ";
			 	f << schools_.at(i).getLevels().at(j).getstudentNumber() << " ";
			 	f << schools_.at(i).getLevels().at(j).getSuccessPercentage() << " ";
			 	f << schools_.at(i).getLevels().at(j).getHasInternship() << " ";
			 	f << schools_.at(i).getLevels().at(j).getInternshipDuration() << " ";
			 	f << schools_.at(i).getLevels().at(j).getInternshipStart() << " ";
			 	f << schools_.at(i).getLevels().at(j).getInternshipEnd() << " ";
			 	
			 	tailleSGL = schools_.at(i).getLevels().at(j).getSkillGroup().skills_.size();
			 	f << tailleSGL << " ";
			 	for (int k = 0; k < tailleSGL; ++k)
			 	{	
			 		int skillId = schools_.at(i).getLevels().at(j).getSkillGroup().skills_.at(k);
			 		f << skillId << " ";
			 	}
			}
			f << endl;
		}
	f.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}

	
}
void World::load(){
	ifstream f;
	int tailleC, tailleSGC, tailleS;
	string nameC, nameGC, nameSGC;
	SkillGroup groupC;
	Skill skill;
	f.open("files/world.sdb");
	if(f){
		/*Reading Compnies*/
		f >> tailleC;
		for (int i = 0; i < tailleC; ++i){
			f >> nameC; 
			Company& company = getCompany(addCompany(nameC));
			f >> tailleSGC;
			int skillId;
			for (int j = 0; j < tailleSGC; ++j){
				f >> skillId;
				company.addSkill(skillId);
			}
		}

		/*Reading Schools*/
		string nameS, nameGS, nameSGS;
		int x, y, tailleLS,id, studentNumber, tailleSGS, internshipEnd, internshipStart;
		Skill skill2;
		SkillGroup groupLS;
		bool hasInternship;
		double successPercentage, internshipDuration;
		f >> tailleS;
		for (int i = 0; i < tailleS; ++i)
		{
			f >> nameS;
			f >> x;
			f >> y;
			School& school = getSchool(addSchool(nameS, x, y));
			f >> tailleLS;
			for (int j = 0; j < tailleLS; ++j)
			{
				f >> id;
				f >> studentNumber;
				f >> successPercentage;
				f >> hasInternship;
				f >> internshipDuration;
				f >> internshipStart;
				f >> internshipEnd;

				int levelId = school.addLevel(id, studentNumber, successPercentage, hasInternship,  internshipDuration, internshipStart, internshipEnd);

				f >> tailleSGS;
				int skillId;
				for (int k = 0; k < tailleSGS; ++k){
					f >> skillId;
					school.addSkillToLevel(skillId, levelId);
				}
			}
		}
		f.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}

}
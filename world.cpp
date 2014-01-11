#include "world.hpp"
World::World(){

}
World::~World(){

}
void World::addSchool(School school){
	schools_.push_back(school);
}

void World::addCompany(Company company){
	companies_.push_back(company);
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
	int tailleC, tailleS, tailleGC, tailleLvelS,tailleSGL;
	
	f.open("world.sdb");
	if(f){
		/*Writing Companies*/
		tailleC =  companies_.size();
		
		f << tailleC << endl;
		for (int i = 0; i < tailleC; ++i)
		{
			f << strReplace(companies_.at(i).getName(),' ','#') << " ";
			f << strReplace(companies_.at(i).getGroup().name_,' ', '#') << " ";
			tailleGC = companies_.at(i).getGroup().skills_.size();
			f << tailleGC << " " ;
			for (int j = 0; j < tailleGC; ++j)
			{
				f << strReplace(companies_.at(i).getGroup().skills_.at(j).name_,' ', '#') << " ";

			}
			f << endl;

		}

		/*Writing Schools*/
		string nameGL; 
		tailleS = schools_.size();
		f << tailleS << endl;
		for (int i = 0; i < tailleS; ++i)
		{
			f << strReplace(schools_.at(i).getName(), ' ', '#') << " ";
			f << schools_.at(i).getPosition().getX() << " " << schools_.at(i).getPosition().getY() << " ";
			tailleLvelS = schools_.at(i).getLevels().size();
			f << tailleLvelS << " ";
			 for (int j = 0; j < tailleLvelS; ++j)
			 {
			 	f << schools_.at(i).getLevels().at(j).getId() << " ";
			 	f << schools_.at(i).getLevels().at(j).getstudentNumber() << " ";
			 	nameGL = schools_.at(i).getLevels().at(j).getSkillGroup().name_;
			 	f << strReplace(nameGL, ' ', '#') << " ";
			 	tailleSGL = schools_.at(i).getLevels().at(j).getSkillGroup().skills_.size();
			 	f << tailleSGL << " ";
			 	for (int k = 0; k < tailleSGL; ++k)
			 	{	string nameSGL = schools_.at(i).getLevels().at(j).getSkillGroup().skills_.at(k).name_;
			 		f << strReplace(nameSGL, ' ', '#') << " ";
			 	}


			 	f << schools_.at(i).getLevels().at(j).getSuccessPercentage() << " ";
			 	f << schools_.at(i).getLevels().at(j).getHasInternship() << " ";
			 	f << schools_.at(i).getLevels().at(j).getInternshipDuration() << " ";
			 	f << schools_.at(i).getLevels().at(j).getInternshipStart() << " ";
			 	f << schools_.at(i).getLevels().at(j).getInternshipEnd() << " ";
			 	


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
	string nameC, nameGC;
	SkillGroup groupC;
	Skill skill;
	f.open("world.sdb");
	if(f){
		/*Reading Compnies*/
		f >> tailleC;
		for (int i = 0; i < tailleC; ++i)
		{
			f >> nameC; 
			Company company(strReplace(nameC,'#',' '));
			f >> nameGC;
			groupC.name_ = nameGC;
			f >> tailleSGC;
			for (int j = 0; j < tailleSGC; ++j)
			{
				f >> nameSGC;
				skill.name_ = strReplace(nameSGC,'#', ' ');
				groupC.skills_.push_back(skill);

			}
			company.addGroupSkills(groupC);
			companies_.push_back(company);

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
			Point position(x, y);
			School school(strReplace(nameS, '#', ' '),position);
			f >> tailleLS;

			for (int j = 0; j < tailleLS; ++j)
			{
				f >> id;
				f >> studentNumber;
				f >> nameGS;
				groupLS.name_ = strReplace(nameGS, '#', ' ');

				f >> tailleSGS;
				for (int k = 0; k < tailleSGS; ++k)
				{
					f >> nameSGS;
					
					skill2.name_ = strReplace(nameSGS, '#', ' ');
					groupLS.skills_.push_back(skill2);
				
				}

				f >> successPercentage;
				f >> hasInternship;
				f >> internshipDuration;
				f >> internshipStart;
				f >> internshipEnd;
				Level level(id, studentNumber, groupLS, successPercentage, hasInternship,  internshipDuration, internshipStart, internshipEnd);
				school.addLevel(level);
			}
			schools_.push_back(school);

		}
		f.close();
	}
	else{
		cerr << "Impossible d'ouvrir le fichier !!" << endl;
	}

}
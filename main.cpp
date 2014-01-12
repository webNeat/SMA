#include <iostream>
#include <sstream>
#include "application.hpp"
int main(int, char**){
	Application::init();
	// Application::saveParams();
	// Application::saveSkills();
	// Application::saveGroupSkills();
	// Application::saveWorld();

	// /*Remplir Params Configuration*/
	// for (int i = 0; i < 10; ++i){
	// 	stringstream ss;
	// 	ss << "succes pourcentage " << i;
	// 	application.addParams(ss.str(), (i*2.0)/1.5);
	// }

	// // map<string, double>& mymap = application.getParams();
	// // for (map<string, double>::iterator it = mymap.begin(); it!= mymap.end(); ++it){
	// // 	cout<< it->first << " => " << it->second << endl;
	// // }

	// /*Remplir SKILLS*/
	// Skill skill1,skill2,skill3;
	
	// skill1.name_ = "C++";
	// skill2.name_ = "Java";
	// skill3.name_ = "PHP";

	// application.addSkill(skill1);
	// application.addSkill(skill2);
	// application.addSkill(skill3);
	
	// /*Remplir Group SKILLS*/
	// SkillGroup& group  =  application.makeSkillGroup("Informatique");
		
	// application.addSkillToGroup(skill1, group);
	// application.addSkillToGroup(skill2, group);
	// application.addSkillToGroup(skill3, group);


	// /*Remplir School*/
	// 	/*Remplir Tab Levels*/
	
	
	// Level level1(1, 20, group, 20.25, false, 2, 7, 9);
	// Level level2(2, 60, group, 30.65, true, 5, 4, 9);

	// Point position(10,10);
	// School school("ISIMA", position);
	// school.addLevel(level1);
	// school.addLevel(level2);

	// //cout << school.toString() << endl;


	// /*Remplir Companie*/

	//  Company company("ATOS");
	//  company.addGroupSkills(group);
	
	// // Remplir WORLD
	// World world;
	// world.addSchool(school);
	// world.addCompany(company);


	// application.addWorld(world);

	// Affichage de L'application
	// cout << application.toString();
	return 0;
}
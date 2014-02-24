#include <fstream>
#include "json.h"
#include "file.hpp"
#include "controller.hpp"
#include "application.hpp"
#include "world.hpp"
using namespace std;

void File::saveConfig(){
	ofstream output("files/config.json");
	json::Object config;
	config["portNumber"] = Controller::getPortNumber();
	output << json::Serialize(config);
	output.close();
}
void File::loadConfig(){
	ifstream input("files/config.json");
	string jsonStr;
	getline(input, jsonStr);
	input.close();
	json::Object config = json::Deserialize(jsonStr);
	Controller::setPortNumber(config["portNumber"]);
	Controller::setUrl(config["url"]);
}

void File::saveParams(){
	ofstream output("files/params.json");
	json::Object paramsObject;
	map<string, double>& params = Application::getParams();
	
	map<string, double>::iterator it = params.begin();
	while(it != params.end()){
		paramsObject[it->first] = it->second;
		it ++;
	}

	output << json::Serialize(paramsObject);
	output.close();
}
void File::loadParams(){
	ifstream input("files/params.json");
	string jsonStr;
	getline(input, jsonStr);
	input.close();
	json::Object paramsObject = json::Deserialize(jsonStr);
	map<string, double> params;

	map<string, json::Value>::iterator it = paramsObject.begin();
	while(it != paramsObject.end()){
		params[it->first] = it->second;
		it ++;
	}
	Application::setParams(params);
	Application::printParams();
}

void File::saveSkills(){
	json::Array skillsArray;
	vector<Skill>& skills = Application::getSkills();	
	vector<Skill>::iterator it = skills.begin();
	while(it != skills.end()){
		json::Object skillObject;
		skillObject["name"] = it->name;
		skillsArray.push_back(skillObject);
		it ++;
	}

	json::Array groupsArray;
	map<string, vector<int> >& groups = Application::getSkillGroups();
	map<string, vector<int> >::iterator gIt = groups.begin();
	while(gIt != groups.end()){
		json::Object groupObject;
		groupObject["name"] = gIt->first;
		json::Array groupSkillsArray;
		vector<int>::iterator sgIt = gIt->second.begin();
		while(sgIt != gIt->second.end()){
			groupSkillsArray.push_back(*sgIt);
			sgIt ++;
		}
		groupObject["skills"] = groupSkillsArray;
		groupsArray.push_back(groupObject);
		gIt ++;
	}

	json::Object skillsObject;
	skillsObject["skills"] = skillsArray;
	skillsObject["groups"] = groupsArray;
	
	ofstream output("files/skills.json");
	output << json::Serialize(skillsObject);
	output.close();
}



void File::loadSkills(){
	ifstream input("files/skills.json");
	string jsonStr;
	getline(input, jsonStr);
	input.close();
	json::Object skillsObject = json::Deserialize(jsonStr);
	vector<Skill> skills;
	json::Array skillsArray = skillsObject["skills"];
	vector<json::Value>::iterator sIt = skillsArray.begin();
	while(sIt != skillsArray.end()){
		json::Object skillObject = *sIt;
		Skill skill;
		skill.name = (string) skillObject["name"];
		skills.push_back(skill);
		sIt ++;
	}
	Application::setSkills(skills);
	
	map<string, vector<int> > skillGroups;
	json::Array skillGroupsArray = skillsObject["groups"];
	vector<json::Value>::iterator gIt = skillGroupsArray.begin();
	while(gIt != skillGroupsArray.end()){
		json::Object groupObject = *gIt;
		vector<int> skillsVector;
		json::Array values = groupObject["skills"];
		vector<json::Value>::iterator sIt = values.begin();
		while(sIt != values.end()){
			skillsVector.push_back(*sIt);
			sIt ++;
		}
		skillGroups[groupObject["name"]] = skillsVector;
		gIt ++;
	}
	Application::setSkillGroups(skillGroups);
}

void File::loadWorld(){
	ifstream input("files/world.json");
	string jsonStr;
	getline(input, jsonStr);
	input.close();
	json::Object world = json::Deserialize(jsonStr);
	
	/********* Company **********/
	
	World::setMonth(world["month"]);
	Agent::setAgentsNumber(world["agentsNumber"]);

	json::Array companiesObject = world["companies"];
	vector<json::Value>::iterator companiesIt = companiesObject.begin();
	while(companiesIt != companiesObject.end()){
		
		json::Object companyObject = (*companiesIt);
		json::Object positionObject = companyObject["position"];

		Company& company = World::getCompany(World::addCompany(companyObject["name"], positionObject["x"], positionObject["y"], companyObject["id"]));
		
		company.setEmployeesNumber(companyObject["employeesNumber"]);
		company.setHiredEmployeesNumber(companyObject["hiredEmployeesNumber"]);
		company.setRetiredEmployeesNumber(companyObject["retiredEmployeesNumber"]);
		company.setAverageEmployeesNumber(companyObject["averageEmployeesNumber"]);
		company.setAverageHiredLauriasNumber(companyObject["averageHiredLauriasNumber"]);
		company.setBeginGivingInternships(companyObject["beginGivingInternships"]);
		company.setEndGivingInternships(companyObject["endGivingInternships"]);
		company.setAverageInternshipsNumber(companyObject["averageInternshipsNumber"]);

		vector<int>& skills = company.getSkills();
		json::Array skillsObject = companyObject["skills"];
		for(int i = 0; i < skillsObject.size(); i++){
			skills.push_back(skillsObject[i]);
		}

		vector<int>& internships = company.getInternshipsIds();
		json::Array internshipsObject = companyObject["internships"];
		for(int i = 0; i < internshipsObject.size(); i++){
			internships.push_back(internshipsObject[i]);
		}

		vector<int>& laureats = company.getLaureatIds();
		json::Array laureatsObject = companyObject["laureats"];
		for(int i = 0; i < laureatsObject.size(); i++){
			laureats.push_back(laureatsObject[i]);
		}

		companiesIt ++;


	}


	/****************** School *********************/
	json::Array schoolsObject = world["schools"];
	vector<json::Value>::iterator schoolsIt = schoolsObject.begin();
	while(schoolsIt != schoolsObject.end()){
		json::Object schoolObject = (*schoolsIt);

		json::Object positionObject = schoolObject["position"];

		School& school = World::getSchool(World::addSchool(schoolObject["name"], positionObject["x"], positionObject["y"], schoolObject["id"]));

		//vector<Level>& levels = school.getLevels();
		json::Array levelsObject = schoolObject["levels"];
		vector<json::Value>::iterator levelsIt = levelsObject.begin();
		while(levelsIt != levelsObject.end()){
			
			json::Object levelObject = (*levelsIt);
			Level& level = school.getLevel(school.addLevel(levelObject["successPercentage"], levelObject["hasInternship"],levelObject["internshipDuration"], levelObject["internshipStart"]));
			level.setId(levelObject["id"]);

			vector<int>& skills = level.getSkills();
			json::Array skillsObject = levelObject["skills"];
			for(int i = 0; i < skillsObject.size(); i++){
				skills.push_back(skillsObject[i]);
			}

			vector<int>& students = level.getstudentIds();
			json::Array studentsObject = levelObject["students"];
			for(int i = 0; i < studentsObject.size(); i++){
				students.push_back(studentsObject[i]);
			}

			levelsIt++;
		}

		vector<int>& laureats = school.getLaureatIds();
		json::Array laureatsObject = schoolObject["laureats"];
		for(int i = 0; i < laureatsObject.size(); i++){
			laureats.push_back(laureatsObject[i]);
		}

		schoolsIt++;

	}

	/******************** Students **********************/
	json::Array sutendtsObject = world["students"];
	vector<json::Value>::iterator studentsIt = sutendtsObject.begin();
	while(studentsIt != sutendtsObject.end()){

		json::Object studentObject = (*studentsIt);
		Student& student = World::getStudent(World::addStudent(studentObject["schoolId"], studentObject["levelId"], studentObject["id"]));
		student.setCurrentInternshipId(studentObject["currentIntershipId"]);
		student.setAngle(studentObject["angle"]);
		student.getCurrentPosition().setX(studentObject["x"]);
		student.getCurrentPosition().setY(studentObject["y"]);

		vector<int>& skills = student.getSkills();
		json::Array skillsObject = studentObject["skills"];
		for(int i = 0; i < skillsObject.size(); i++){
			skills.push_back(skillsObject[i]);
		}

		vector<int>& internships = student.getInternShips();
		json::Array internshipsObject = studentObject["internships"];
		for(int i = 0; i < internshipsObject.size(); i++){
			internships.push_back(internshipsObject[i]);
		}

		studentsIt++;
	}

	/**************** Laureats *****************/
	json::Array laureatsObject = world["laureats"];
	vector<json::Value>::iterator laureatsIt = laureatsObject.begin();
	while(laureatsIt != laureatsObject.end()){

		json::Object laureatObject = (*laureatsIt);
		Laureat& laureat = World::getLaureat(World::addLaureat(laureatObject["schoolId"], laureatObject["id"]));
		laureat.setCurrentCompanyId(laureatObject["currentCompanypId"]);

		vector<int>& skills = laureat.getSkills();
		json::Array skillsObject = laureatObject["skills"];
		for(int i = 0; i < skillsObject.size(); i++){
			skills.push_back(skillsObject[i]);
		}

		vector<int>& internships = laureat.getInternShips();
		json::Array internshipsObject = laureatObject["internships"];
		for(int i = 0; i < internshipsObject.size(); i++){
			internships.push_back(internshipsObject[i]);
		}

		laureatsIt++;
	}

	/*******************Internship**************************/
	json::Array internshipsObject = world["internships"];
	vector<json::Value>::iterator internshipsIt = internshipsObject.begin();
	while(internshipsIt != internshipsObject.end()){

		json::Object internshipObject = (*internshipsIt);
		Internship& internship = World::getInternship(World::addInternship(internshipObject["companyId"]));
		internship.setStudentId(internshipObject["studentId"]);
		internship.setAvailable(internshipObject["available"]);


		vector<int>& skills = internship.getSkills();
		json::Array skillsObject = internshipObject["skills"];
		for(int i = 0; i < skillsObject.size(); i++){
			skills.push_back(skillsObject[i]);
		}

		internshipsIt++;
	}
}

void File::saveWorld(){
	ofstream output("files/world.json");
	json::Object world;
	world["month"] = World::getMonth();	
	world["agentsNumber"] = Agent::getAgentsNumber();

	/***************************Companies*******************************/

	json::Array companiesObject;
	map<int, Company>& companies = World::getCompanies();
	map<int, Company>::iterator companiesIt = companies.begin();
	while(companiesIt != companies.end()){
		json::Object companyObject;

		companyObject["id"] = companiesIt->first;
		companyObject["name"] = companiesIt->second.getName();
		companyObject["employeesNumber"] = companiesIt->second.getEmployeesNumber();
		companyObject["hiredEmployeesNumber"] = companiesIt->second.getHiredEmployeesNumber();
		companyObject["retiredEmployeesNumber"] = companiesIt->second.getRetiredEmployeesNumber();
		companyObject["averageEmployeesNumber"] = companiesIt->second.getAverageEmployeesNumber();
		companyObject["averageHiredLauriasNumber"] = companiesIt->second.getAverageHiredLauriasNumber();
		companyObject["beginGivingInternships"] = companiesIt->second.getBeginGivingInternships();
		companyObject["endGivingInternships"] = companiesIt->second.getEndGivingInternships();
		companyObject["averageInternshipsNumber"]  = companiesIt->second.getAverageInternshipsNumber();
		
		json::Object positionObject;
		positionObject["x"] = companiesIt->second.getPosition().getX();
		positionObject["y"] = companiesIt->second.getPosition().getY();
		
		companyObject["position"] = positionObject;

		json::Array skillsObject;
		vector<int> skills = companiesIt->second.getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		companyObject["skills"] = skillsObject;


		json::Array InternshipsIdsObject;
		vector<int> internships = companiesIt->second.getInternshipsIds();
		
		for(int i = 0; i < internships.size(); i++){
			InternshipsIdsObject.push_back(internships.at(i));

		}
		companyObject["internships"] = InternshipsIdsObject;
		
		json::Array laureatIdsObject;
		vector<int> laureats = companiesIt->second.getLaureatIds();
	
		for(int i = 0; i < laureats.size(); i++){
			laureatIdsObject.push_back(laureats.at(i));

		}
		companyObject["laureats"] = laureatIdsObject;
		companiesObject.push_back(companyObject);
		companiesIt ++;
	}

	world["companies"] = companiesObject;


	/*******************************Schools**********************************/
	json::Array schoolsObject;
	map<int, School>& schools = World::getSchools(); 
	map<int, School>::iterator schoolsIt = schools.begin();
	while(schoolsIt != schools.end()){
		json::Object schoolObject;
		schoolObject["id"] = schoolsIt->first;
		schoolObject["name"] = schoolsIt->second.getName();
		
		json::Object positionObject;
		positionObject["x"] = schoolsIt->second.getPosition().getX();
		positionObject["y"] = schoolsIt->second.getPosition().getY();
		
		schoolObject["position"] = positionObject;

		json::Array levelsObject;
		vector<Level>& levels = schoolsIt->second.getLevels();
		vector<Level>::iterator levelsIt = levels.begin();
		while(levelsIt != levels.end()){
			
			json::Object levelObject;
			
			levelObject["id"] = levelsIt->getId();
			levelObject["successPercentage"] = levelsIt->getSuccessPercentage();
			levelObject["hasInternship"] = levelsIt->getHasInternship();			
			levelObject["internshipStart"] = levelsIt->getInternshipStart();
			levelObject["internshipDuration"] = levelsIt->getInternshipDuration();


			json::Array skillsObject;
			vector<int>& skills = levelsIt->getSkills();
			
			for(int i = 0; i < skills.size(); i++){
				skillsObject.push_back(skills.at(i));

			}
			levelObject["skills"] = skillsObject;

		
			json::Array studentObject;
			vector<int>& students = levelsIt->getstudentIds();
			
			for(int i = 0; i < students.size(); i++){
				studentObject.push_back(students.at(i));

			}
			levelObject["students"] = studentObject;

			levelsObject.push_back(levelObject);
			levelsIt ++;	

		}
		schoolObject["levels"] = levelsObject;


		json::Array laureatObject;
		vector<int>& laureats = schoolsIt->second.getLaureatIds();
		
		for(int i = 0; i < laureats.size(); i++){
			laureatObject.push_back(laureats.at(i));

		}
		schoolObject["laureats"] = laureatObject;



		schoolsObject.push_back(schoolObject);
		schoolsIt ++;
	}

	world["schools"] = schoolsObject;



	/********************** Students **********************************/
	json::Array studentsObject;
	map<int, Student>& students = World::getStudents();
	map<int, Student>::iterator studentsIt = students.begin();
	// cout << students.size() << " students saved !" << endl; 
	while(studentsIt != students.end()){		
		json::Object studentObject;

		studentObject["id"] = studentsIt->first;
		studentObject["schoolId"] = studentsIt->second.getSchoolId();
		studentObject["levelId"] = studentsIt->second.getLevelId();
		studentObject["currentIntershipId"] = studentsIt->second.getCurrentInternshipId();
		studentObject["angle"] = studentsIt->second.getAngle();
		studentObject["x"] = studentsIt->second.getCurrentPosition().getX();
		studentObject["y"] = studentsIt->second.getCurrentPosition().getY();

		json::Array skillsObject;
		vector<int>& skills = studentsIt->second.getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		studentObject["skills"] = skillsObject;

		json::Array positionsArray;
		vector<Point>& positions = studentsIt->second.getPositions();
		vector<Point>::iterator positionsIt = positions.begin();
		while(positionsIt != positions.end()){
			json::Object positionObject;
			positionObject["x"] = positionsIt->getX();
			positionObject["y"] = positionsIt->getY();
			positionsArray.push_back(positionObject);
			positionsIt ++;
		}
		studentObject["positions"] = positionsArray;

		json::Array internshipObject;
		vector<int>& internships = studentsIt->second.getInternShips();
		
		for(int i = 0; i < internships.size(); i++){
			internshipObject.push_back(internships.at(i));

		}
		studentObject["internships"] = internshipObject;


		studentsObject.push_back(studentObject);
		studentsIt ++;
	}
	world["students"] = studentsObject;

	/********************* Laureat *****************************************/
	json::Array laureatsObject;
	map<int, Laureat>& laureats = World::getLaureats();
	map<int, Laureat>::iterator laureatsIt = laureats.begin();
	while(laureatsIt != laureats.end()){
		
		json::Object laureatObject;

		laureatObject["id"] = laureatsIt->first;
		laureatObject["schoolId"] = laureatsIt->second.getSchoolId();
		laureatObject["currentCompanypId"] = laureatsIt->second.getCurrentCompanypId();

		json::Array skillsObject;
		vector<int>& skills = laureatsIt->second.getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		laureatObject["skills"] = skillsObject;


		json::Array internshipsObject;
		vector<int>& internships = laureatsIt->second.getInternShips();
		
		for(int i = 0; i < internships.size(); i++){
			internshipsObject.push_back(internships.at(i));

		}
		laureatObject["internships"] = internshipsObject;


		laureatsObject.push_back(laureatObject);
		laureatsIt ++;


	}
	world["laureats"] = laureatsObject;

	/********************* Internship *****************************************/
	json::Array internshipsObject;
	vector<Internship>& internships = World::getInternships();
	vector<Internship>::iterator internshipsIt = internships.begin();
	while(internshipsIt != internships.end()){
		
		json::Object internshipObject;

		internshipObject["companyId"] = internshipsIt->getCompanyId();
		internshipObject["studentId"] = internshipsIt->getStudentId();
		internshipObject["available"] = internshipsIt->getAvailable();

		json::Array skillsObject;
		vector<int>& skills = internshipsIt->getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		internshipObject["skills"] = skillsObject;

		internshipsObject.push_back(internshipObject);
		internshipsIt ++;
	}
	world["internships"] = internshipsObject;

	output << json::Serialize(world);
	output.close();
}
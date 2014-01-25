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
}

// void File::loadWorld(){
// 	ifstream input("files/world.json");
// 	string jsonStr;
// 	getline(input, jsonStr);
// 	input.close();
// 	json::Object world = json::Deserialize(jsonStr);
	
// 	/********* Company **********/
	
// 	map<string, json::Value>::iterator companiesIt = world.begin();
// 	World::setMonth(world["month"]);
// 	companiesIt++;
	


// }

void File::saveWorld(){
	ofstream output("files/world.json");
	json::Object world;
	world["month"] = World::getMonth();	

	/***************************Companies*******************************/

	json::Array companiesObject;
	vector<Company>& companies = World::getCompanies();
	vector<Company>::iterator companiesIt = companies.begin();
	while(companiesIt != companies.end()){
		json::Object companyObject;

		companyObject["id"] = companiesIt->getId();
		companyObject["name"] = companiesIt->getName();
		companyObject["employessNumber"] = companiesIt->getEmployessNumber();
		companyObject["hiredEmployeesNumber"] = companiesIt->getIHiredEmployeesNumber();
		companyObject["retiredEmployeesNumber"] = companiesIt->getRetiredEmployeesNumber();
		companyObject["averageEmployeesNumber"] = companiesIt->getAverageEmployeesNumber();
		companyObject["averageHiredLauriasNumber"] = companiesIt->getAverageHiredLauriasNumber();
		companyObject["beginGivingInternships"] = companiesIt->getBeginGivingInternships();
		companyObject["endGivingInternships"] = companiesIt->getEndGivingInternships();
		
		json::Array skillsObject;
		vector<int> skills = companiesIt->getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		companyObject["skills"] = skillsObject;


		json::Array InternshipsIdsObject;
		vector<int> internships = companiesIt->getInternshipsIds();
		
		for(int i = 0; i < internships.size(); i++){
			InternshipsIdsObject.push_back(internships.at(i));

		}
		companyObject["internships"] = InternshipsIdsObject;
		
		json::Array laureatIdsObject;
		vector<int> laureats = companiesIt->getLaureatIds();
	
		for(int i = 0; i < laureats.size(); i++){
			laureatIdsObject.push_back(laureats.at(i));

		}
		companyObject["laureats"] = laureatIdsObject;


		json::Array averageInternshipsNumberObject;
		vector<int> averageinternships = companiesIt->getAverageInternshipsNumber();
	
		for(int i = 0; i < averageinternships.size(); i++){
			averageInternshipsNumberObject.push_back(averageinternships.at(i));

		}
		companyObject["averageInternshipsNumber"] = averageInternshipsNumberObject;


		companiesObject.push_back(companyObject);
		companiesIt ++;
	}


	world["companies"] = companiesObject;


	/*******************************Schools**********************************/
	json::Array schoolsObject;
	vector<School>& scholls = World::getSchools(); 
	vector<School>::iterator schoolsIt = scholls.begin();
	while(schoolsIt != scholls.end()){
		json::Object schoolObject;
		schoolObject["id"] = schoolsIt->getId();
		schoolObject["name"] = schoolsIt->getName();
		
		json::Object positionObject;
		positionObject["x"] = schoolsIt->getPosition().getX();
		positionObject["y"] = schoolsIt->getPosition().getY();
		
		schoolObject["position"] = positionObject;

		json::Array levelsObject;
		vector<Level>& levels = schoolsIt->getLevels();
		vector<Level>::iterator levelsIt = levels.begin();
		while(levelsIt != levels.end()){
			
			json::Object levelObject;
			
			levelObject["id"] = levelsIt->getId();
			levelObject["successPercentage"] = levelsIt->getSuccessPercentage();
			levelObject["hasInternship"] = levelsIt->getHasInternship();			
			levelObject["internshipStrat"] = levelsIt->getInternshipStart();
			levelObject["internshipEnd"] = levelsIt->getInternshipEnd();


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
		vector<int>& laureats = schoolsIt->getLaureatIds();
		
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
	vector<Student>& students = World::getStudents();
	vector<Student>::iterator studentsIt = students.begin();
	while(studentsIt != students.end()){
		
		json::Object studentObject;

		studentObject["schoolId"] = studentsIt->getSchoolId();
		studentObject["levelId"] = studentsIt->getLevelId();
		studentObject["currentIntershipId"] = studentsIt->getCurrenInternshipId();

		json::Array skillsObject;
		vector<int>& skills = studentsIt->getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		studentObject["skills"] = skillsObject;

		json::Array internshipObject;
		vector<int>& internships = studentsIt->getInternShips();
		
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
	vector<Laureat>& laureats = World::getLaureats();
	vector<Laureat>::iterator laureatsIt = laureats.begin();
	while(laureatsIt != laureats.end()){
		
		json::Object laureatObject;

		laureatObject["schoolId"] = laureatsIt->getSchoolId();
		laureatObject["currentCompanypId"] = laureatsIt->getCurrentCompanypId();

		json::Array skillsObject;
		vector<int>& skills = laureatsIt->getSkills();
		
		for(int i = 0; i < skills.size(); i++){
			skillsObject.push_back(skills.at(i));

		}
		laureatObject["skills"] = skillsObject;


		json::Array internshipsObject;
		vector<int>& internships = laureatsIt->getInternShips();
		
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



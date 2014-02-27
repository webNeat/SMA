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
	jsonToWorld(world);
}

void File::saveWorld(){
	ofstream output("files/world.json");
	json::Object world = worldToJson();
	output << json::Serialize(world);
	output.close();
}

vector<int> File::arrayToVector(json::Array& array){
	vector<int> list;
	vector<json::Value>::iterator it = array.begin();
	while(it != array.end()){
		list.push_back(*it);
		it ++;
	}
	return list;
}
json::Array File::vectorToArray(vector<int>& list){
	json::Array array;
	vector<int>::iterator it = list.begin();
	while(it != list.end()){
		array.push_back(*it);
		it ++;
	}
	return array;
}

Company File::jsonToCompany(json::Object& obj){
	Company company(
		obj["name"],
 		obj["x"],
 		obj["y"],
 		obj["internshipsNumber"],
 		obj["internshipsEcart"],
 		obj["start"],
 		obj["end"],
 		obj["skillsByInternship"]
 	);
 	company.setId(obj["id"]);

 	json::Array skills = obj["skills"];
 	company.setSkills(arrayToVector(skills));

 	json::Array internships = obj["internships"];
 	company.setInternshipsIds(arrayToVector(internships));

 	json::Array laureats = obj["laureats"];
 	company.setLaureatIds(arrayToVector(laureats));

 	return company;
}
json::Object File::companyToJson(Company& company){
	json::Object obj;
	obj["name"] = company.getName();
	obj["x"] = company.getPosition().getX();
	obj["y"] = company.getPosition().getY();
	obj["internshipsNumber"] = company.getAverageInternshipsNumber();
	obj["internshipsEcart"] = company.getInternshipsNumberEcart();
	obj["start"] = company.getBeginGivingInternships();
	obj["end"] = company.getEndGivingInternships();
	obj["skillsByInternship"] = company.getSkillsPerInternship();
	obj["id"] = company.getId();
	obj["skills"] = vectorToArray(company.getSkills());
	obj["internships"] = vectorToArray(company.getInternshipsIds());
	obj["laureats"] = vectorToArray(company.getLaureatIds());

	obj["availableInternships"] = company.getAvailableInternships();
	obj["hiredStudents"] = company.getHiredStudents();
	return obj;
}

Internship File::jsonToInternship(json::Object& obj){
	Internship in(obj["companyId"]);
	in.setStudentId(obj["studentId"]);
	in.setAvailable(obj["available"]);
 	json::Array skills = obj["skills"];
	in.setSkills(arrayToVector(skills));
	return in;
}
json::Object File::internshipToJson(Internship& in){
	json::Object obj;
	obj["companyId"] = in.getCompanyId();
	obj["studentId"] = in.getStudentId();
	obj["available"] = in.getAvailable();
	obj["skills"] = vectorToArray(in.getSkills());
	return obj;
}

Laureat File::jsonToLaureat(json::Object& obj){
	Laureat laureat;
	laureat.setId(obj["id"]);
	laureat.setSchoolId(obj["schoolId"]);
	laureat.setCurrentCompanyId(obj["currentCompanyId"]);
	laureat.getCurrentPosition().setX(obj["x"]);
	laureat.getCurrentPosition().setY(obj["y"]);
	laureat.setAngle(obj["angle"]);
 	json::Array skills = obj["skills"];
	laureat.setSkills(arrayToVector(skills));
 	json::Array internships = obj["internships"];
	laureat.setInternships(arrayToVector(internships));
	vector<Point>& positions = laureat.getPositions();
	json::Array array = obj["positions"];
	vector<json::Value>::iterator it = array.begin();
	while( it != array.end() ){
		json::Object p = *it;
		Point point(p["x"],p["y"]);
		positions.push_back(point);
		it ++;
	}
	return laureat;
}
json::Object File::laureatToJson(Laureat& laureat){
	json::Object obj;
	obj["id"] = laureat.getId();
	obj["schoolId"] = laureat.getSchoolId();
	obj["currentCompanyId"] = laureat.getCurrentCompanyId();
	obj["x"] = laureat.getCurrentPosition().getX();
	obj["y"] = laureat.getCurrentPosition().getY();
	obj["angle"] = laureat.getAngle();
	obj["skills"] = vectorToArray(laureat.getSkills());
	obj["internships"] = vectorToArray(laureat.getInternships());
	json::Array array;
	vector<Point>::iterator it = laureat.getPositions().begin();
	while( it != laureat.getPositions().end() ){
		json::Object p;
		p["x"] = it->getX();
		p["y"] = it->getY();
		array.push_back(p);
		it ++;
	}
	obj["positions"] = array;
	return obj;
}

Level File::jsonToLevel(json::Object& obj){
	Level l(
		obj["successPercentage"], 
		obj["hasInternship"], 
		obj["internshipDuration"], 
		obj["internshipStart"]
	);
 	json::Array skills = obj["skills"];
	l.setSkills(arrayToVector(skills));
 	json::Array students = obj["students"];
	l.setStudentIds(arrayToVector(students));
	return l;
}
json::Object File::levelToJson(Level& level){
	json::Object obj;
	obj["successPercentage"] = level.getSuccessPercentage();
	obj["hasInternship"] = level.getHasInternship();
	obj["internshipDuration"] = level.getInternshipDuration();
	obj["internshipStart"] = level.getInternshipStart();
	obj["skills"] = vectorToArray(level.getSkills());
	obj["students"] = vectorToArray(level.getStudentIds());
	return obj;
}

School File::jsonToSchool(json::Object& obj){
	School school(
		obj["name"],
		obj["average"],
		obj["ecart"],
		obj["x"],
		obj["y"]
	);
	school.setId(obj["id"]);
	json::Array laureats = obj["laureats"];
	school.setLaureatIds(arrayToVector(laureats));
	vector<Level>& levels = school.getLevels();
	json::Array array = obj["levels"];
	vector<json::Value>::iterator it = array.begin();
	while( it != array.end() ){
		json::Object l = *it;
		levels.push_back(jsonToLevel(l));
		it ++;
	}
	return school;
}
json::Object File::schoolToJson(School& school){
	json::Object obj;
	obj["id"] = school.getId();
	obj["name"] = school.getName();
	obj["average"] = school.getAverage();
	obj["ecart"] = school.getEcart();
	obj["x"] = school.getPosition().getX();
	obj["y"] = school.getPosition().getY();
	obj["laureats"] = vectorToArray(school.getLaureatIds());
	json::Array array;
	vector<Level>::iterator it = school.getLevels().begin();
	while( it != school.getLevels().end() ){
		array.push_back(levelToJson(*it));
		it ++;
	}
	obj["levels"] = array;

	obj["workingLaureats"] = school.getWorkingLaureats();
	obj["studentsShouldHaveInternship"] = school.studentsShouldHaveInternship();
	obj["studentsHavingInternship"] = school.getStudentsHavingInternship();
	return obj;
}

Student File::jsonToStudent(json::Object& obj){
	Student student(
		obj["schoolId"],
		obj["levelId"],
		obj["x"],
		obj["y"]
	);
	student.setId(obj["id"]);
	student.setAngle(obj["angle"]);
	student.setCurrentInternshipId(obj["currentInternshipId"]);
 	json::Array skills = obj["skills"];
	student.setSkills(arrayToVector(skills));
 	json::Array internships = obj["internships"];
	student.setInternships(arrayToVector(internships));
	vector<Point>& positions = student.getPositions();
	json::Array array = obj["positions"];
	vector<json::Value>::iterator it = array.begin();
	while( it != array.end() ){
		json::Object p = *it;
		Point point(p["x"],p["y"]);
		positions.push_back(point);
		it ++;
	}
	return student;
}
json::Object File::studentToJson(Student& student){
	json::Object obj;
	obj["schoolId"] = student.getSchoolId() ;
	obj["levelId"] = student.getLevelId() ;
	obj["x"] = student.getCurrentPosition().getX();
	obj["y"] = student.getCurrentPosition().getY();
	obj["id"] = student.getId() ;
	obj["angle"] = student.getAngle() ;
	obj["currentInternshipId"] = student.getCurrentInternshipId() ;
	obj["skills"] = vectorToArray(student.getSkills());
	obj["internships"] = vectorToArray(student.getInternships());
	json::Array array;
	vector<Point>::iterator it = student.getPositions().begin();
	while( it != student.getPositions().end() ){
		json::Object p;
		p["x"] = it->getX();
		p["y"] = it->getY();
		array.push_back(p);
		it ++;
	}
	obj["positions"] = array;
	return obj;
}

void File::jsonToWorld(json::Object& obj){
	World::setMonth(obj["month"]);

	map<int, Company>& companies = World::getCompanies();
	json::Array companiesArray = obj["companies"];
	vector<json::Value>::iterator companiesIt = companiesArray.begin();
	while( companiesIt != companiesArray.end() ){
		json::Object c = *companiesIt;
		companies.insert(pair<int, Company>(c["id"] , jsonToCompany(c)));
		companiesIt ++;
	}
	
	map<int, School>& schools = World::getSchools();
	json::Array schoolsArray = obj["schools"];
	vector<json::Value>::iterator schoolsIt = schoolsArray.begin();
	while( schoolsIt != schoolsArray.end() ){
		json::Object c = *schoolsIt;
		schools.insert(pair<int, School>(c["id"] , jsonToSchool(c)));
		schoolsIt ++;
	}
	
	map<int, Student>& students = World::getStudents();
	json::Array studentsArray = obj["students"];
	vector<json::Value>::iterator studentsIt = studentsArray.begin();
	while( studentsIt != studentsArray.end() ){
		json::Object c = *studentsIt;
		students.insert(pair<int, Student>(c["id"] , jsonToStudent(c)));
		studentsIt ++;
	}
	
	map<int, Laureat>& laureats = World::getLaureats();
	json::Array laureatsArray = obj["laureats"];
	vector<json::Value>::iterator laureatsIt = laureatsArray.begin();
	while( laureatsIt != laureatsArray.end() ){
		json::Object c = *laureatsIt;
		laureats.insert(pair<int, Laureat>(c["id"] , jsonToLaureat(c)));
		laureatsIt ++;
	}

	vector<Internship>& internships = World::getInternships();
	json::Array internshipsArray = obj["internships"];
	vector<json::Value>::iterator internshipsIt = internshipsArray.begin();
	while( internshipsIt != internshipsArray.end() ){
		json::Object c = *internshipsIt;
		internships.push_back(jsonToInternship(c));
		internshipsIt ++;
	}

}

json::Object File::worldToJson(){
	json::Object obj;
	obj["month"] = World::getMonth();
	
	json::Array companiesArray;
	map<int, Company>::iterator companiesIt = World::getCompanies().begin();
	while( companiesIt !=  World::getCompanies().end() ){
		companiesArray.push_back(companyToJson(companiesIt->second));
		companiesIt ++;
	}
	obj["companies"] = companiesArray;
	
	json::Array schoolsArray;
	map<int, School>::iterator schoolsIt = World::getSchools().begin();
	while( schoolsIt !=  World::getSchools().end() ){
		schoolsArray.push_back(schoolToJson(schoolsIt->second));
		schoolsIt ++;
	}
	obj["schools"] = schoolsArray;

	json::Array studentsArray;
	map<int, Student>::iterator studentsIt = World::getStudents().begin();
	while( studentsIt !=  World::getStudents().end() ){
		studentsArray.push_back(studentToJson(studentsIt->second));
		studentsIt ++;
	}
	obj["students"] = studentsArray;

	json::Array laureatsArray;
	map<int, Laureat>::iterator laureatsIt = World::getLaureats().begin();
	while( laureatsIt !=  World::getLaureats().end() ){
		laureatsArray.push_back(laureatToJson(laureatsIt->second));
		laureatsIt ++;
	}
	obj["laureats"] = laureatsArray;

	json::Array internshipsArray;
	vector<Internship>::iterator internshipsIt = World::getInternships().begin();
	while( internshipsIt !=  World::getInternships().end() ){
		internshipsArray.push_back(internshipToJson(*internshipsIt));
		internshipsIt ++;
	}
	obj["internships"] = internshipsArray;

	obj["studentsHavingInternship"] = World::getStudentsHavingInternship();
	obj["studentsShouldHaveInternship"] = World::studentsShouldHaveInternship();
	obj["workingLaureats"] = World::getWorkingLaureats();

	return obj;
}
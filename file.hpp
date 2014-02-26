#ifndef FILE_HPP
#define FILE_HPP 1

#include "application.hpp"
#include "json.h"

class File {
public:
	static void saveConfig();
	static void loadConfig();

	static void saveParams();
	static void loadParams();

	static void saveSkills();
	static void loadSkills();


	static void saveWorld();
	static void loadWorld();

	static vector<int> arrayToVector(json::Array& array);
	static School jsonToSchool(json::Object& obj);
	static Company jsonToCompany(json::Object& obj);
	static Internship jsonToInternship(json::Object& obj);
	static Laureat jsonToLaureat(json::Object& obj);
	static Level jsonToLevel(json::Object& obj);
	static Student jsonToStudent(json::Object& obj);
	static void jsonToWorld(json::Object& obj);

	static json::Array vectorToArray(vector<int>& list); 
	static json::Object schoolToJson(School& school);
	static json::Object companyToJson(Company& company);
	static json::Object internshipToJson(Internship& intership);
	static json::Object laureatToJson(Laureat& laureat);
	static json::Object levelToJson(Level& level);
	static json::Object studentToJson(Student& student);
	static json::Object worldToJson();

};
#endif
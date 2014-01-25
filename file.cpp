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

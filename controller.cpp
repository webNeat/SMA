#include <cstdlib>
#include "controller.hpp"
#include "file.hpp"
#include "application.hpp"

int Controller::portNumber_;
string Controller::url_;

void Controller::start(){
	File::loadParams();
	File::loadConfig();
	// File::loadSkills();
	File::loadWorld();

	World::addSchool("IFMA");
	// School& ifma = World::getSchool( World::addSchool("IFMA") );
	// Level& firstYear = isima.getLevel(isima.addLevel(0.95, true, 3, 5));
	// firstYear.addSkill(0);
	// firstYear.addSkill(3);
	// Level& secondYear = isima.getLevel(isima.addLevel(0.92, true, 5, 4));
	// secondYear.addSkill(6);
	// isima.generateStudents();

	// Company& atos = World::getCompany(World::addCompany("ATOS"));
	File::saveWorld();

	ServerSocket server(portNumber_);
	string cmd = "firefox " + url_ + " &";
	// system(cmd.c_str());
	string request;
	while ( true ){
		try{
	  		ServerSocket new_sock;
	  		server.accept ( new_sock );
			new_sock >> request;
			if(request.compare("update_params") == 0){
				new_sock << updateParams();
			}else if(request.compare("exit") == 0){
				break;
			}
		} catch(exception e){
			cout << "Error Happened !" << endl;
		}
	}
}

string Controller::updateParams(){
	File::loadParams();
	return "done";
}
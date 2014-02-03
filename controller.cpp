#include <cstdlib>
#include "controller.hpp"
#include "file.hpp"
#include "application.hpp"

int Controller::portNumber_;
string Controller::url_;

void Controller::start(){
	File::loadParams();
	File::loadConfig();
	File::loadSkills();
	// File::loadWorld();
	School& isima = World::getSchool(World::addSchool("ISIMA"));
	isima.addLevel( 0.9, false, 0, -1);
	isima.addSkillToLevel(0,0);
	isima.addSkillToLevel(1,0);
	isima.addLevel( 0.85, true, 5, 4);
	isima.addSkillToLevel(2,1);
	isima.addSkillToLevel(4,1);
	Company& atos = World::getCompany(World::addCompany("ATOS"));
	atos.addSkill(0);
	atos.addSkill(1);
	atos.addSkill(2);
	atos.addSkill(3);
	File::saveWorld();
	act();

	ServerSocket server(portNumber_);
	string cmd = "firefox " + url_ + " &";
	system(cmd.c_str());
	string request;
	string response;
	while ( true ){
		try{
	  		ServerSocket new_sock;
	  		cout << "waiting ... " << endl;
	  		server.accept ( new_sock );
	  		cout << "some request !" << endl;
			new_sock >> request;
	  		cout << "action: " << request << endl;
			if(request.compare("update_params") == 0){
				new_sock << updateParams();
			}else if(request.compare("act") == 0){
				new_sock << act();
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

string Controller::act(){
	World::act();
	File::saveWorld();
	return "done";
}
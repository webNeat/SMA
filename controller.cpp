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
	File::loadWorld();
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
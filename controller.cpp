#include "controller.hpp"
#include "file.hpp"
#include "application.hpp"

ServerSocket Controller::server_;
int Controller::portNumber_;

void Controller::start(){
	File::loadParams();
	File::loadConfig();
	ServerSocket server(portNumber_);
	server_ = server;
	string request;
	while ( true ){
  		ServerSocket new_sock;
  		server.accept ( new_sock );
		new_sock >> request;
		if(request.compare("update_params") == 0){
			new_sock << updateParams();
		}else if(request.compare("exit") == 0){
			break;
		}
	}
}

string Controller::updateParams(){
	File::loadParams();
	return "done";
}
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP 1
#include <map>
#include <string>
#include "sockets.hpp"
#include "application.hpp"
using namespace std;

class Controller {
private:
	static ServerSocket server_;
	static int portNumber_;
public:
	static int getPortNumber(){
		return portNumber_;
	};
	static void setPortNumber(int pn){
		portNumber_ = pn;
	};
	static void start();
	static string updateParams();
	static string run();
	static string act();
	static string save();
	static string load();
};
#endif
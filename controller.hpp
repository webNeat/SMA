#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP 1
#include <map>
#include <string>
#include "sockets.hpp"
#include "application.hpp"
using namespace std;

class Controller {
private:
	static int portNumber_;
	static string browser_;
	static string url_;
public:
	static int getPortNumber(){
		return portNumber_;
	}
	static void setPortNumber(int pn){
		portNumber_ = pn;
	}
	static void setBrowser(string name){
		browser_ = name;
	}
	static void setUrl(string name){
		url_ = name;
	}
	static void start();
	static string updateParams();
	static string run();
	static string act();
	static string save();
	static string load();
	static string sample();
};
#endif
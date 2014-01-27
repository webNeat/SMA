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
	static string url_;
public:
	static int getPortNumber(){
		return portNumber_;
	};
	static void setPortNumber(int pn){
		portNumber_ = pn;
	};
	static void setUrl(string url){
		url_ = url;
	};
	static void start();
	static string updateParams();
	static string run();
	static string act();
	static string save();
	static string load();
};
#endif
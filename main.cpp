#include <iostream>
#include <sstream>
#include "application.hpp"
int main(int, char**){
	Application::init();
	cout << Application::toString();
	return 0;
}
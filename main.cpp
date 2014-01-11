#include <iostream>
#include "lib.hpp"
#include "interface.hpp"

int main(int, char** ){
	// string str = "";
	// vector<string> vs = splitString(trim(str),':');
	// vector<string>::iterator it = vs.begin();
	// while(it != vs.end()){
	// 	cout << (*it) << endl;
	// 	it++;
	// }
	Interface interface;
	cout << "************ Parsing ********************" << endl;
	interface.parse("files/windows.stpl");
	cout << "************ Results ********************" << endl;
	interface.displayWindows();
	return 0;
}
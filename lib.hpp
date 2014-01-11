#ifndef LIB_H
#define LIB_H 1

#include <string>
#include <vector>
using namespace std;
// some usefull functions
string& trim(string&);
vector<string> splitString(string haystack, char separateur);
int strToInt(string&);
string& strReplace(string&, char, char);
#endif
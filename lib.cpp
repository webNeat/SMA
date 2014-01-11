#include <iostream>
#include <sstream>
#include "lib.hpp"

vector<string> splitString(string haystack, char separateur){
	vector<string> array;
	string element = "";
	int i = 0,
		size = haystack.size();
	while(i < size){
		if(haystack[i] == separateur){
			array.push_back(element);
			element = "";
		}else{
			element = element + haystack[i];
		}
		i++;
	}
	array.push_back(element);
	return array;
}

string& trim(string& text){
	int size = text.size();
	if(size == 0)
		return text;
	// ltrim
	int i = 0;
	char c = text.at(i);
	while( (c == ' ' || c == '\t') && i < size){	
		i++;
		c = text[i];
	}
	if(i == size){
		text = "";
		return text;
	}
	for(int j = i; j < size; j++){
		text.at(j - i) = text.at(j);
	}
	size -= i;
	text.resize(size);
	// rtrim
	i = size - 1;
	c = text.at(i);
	while(c == ' ' || c == '\t'){
		i--;
		c = text.at(i);
	}
	text.resize(i + 1);
	return text;
}

int strToInt(string& str){
	stringstream ss(str);
	int x;
	ss >> x;
	return x;
}
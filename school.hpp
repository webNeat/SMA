#ifndef SCHOOL_HPP
#define SCHOOL_HPP
#include "level.hpp"
#include "point.hpp"
#include <string>
#include <vector>
using namespace std;
class School {

	private:
		string name_;
		Point position_;
		vector<Level> levels_;
	public:
	 	string getName();
	 	void setName(string name);
		Point& getPosition();
		void addLevel(Level l);
		vector<Level>& getLevels();
	 	string toString();
	 	School(string name, Point position);
	 	School();
		~School();
	// 	School(const School &s);
	// 	void setLevels(vector<Level> levels);
	// 	School& operator=(const School &s); 

		

	
};
#endif
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
	 	School();
	 	School(string name, int, int);
		~School();

	 	string getName();
	 	void setName(string name);

		Point& getPosition();
		
		int addLevel(int, int, double, bool, double, int, int);
		vector<Level>& getLevels();
		Level& getLevel(int);
		bool addSkillToLevel(int, int);

	 	string toString();
	// 	School(const School &s);
	// 	void setLevels(vector<Level> levels);
	// 	School& operator=(const School &s); 
};
#endif
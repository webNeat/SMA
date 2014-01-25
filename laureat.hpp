#ifndef Laureat_HPP
#define Laureat_HPP
#include <vector>
#include "agent.hpp"
using namespace std;

class Laureat : Agent {
private:
	int schoolId_;
	vector<int> skills_;
	vector<int> internships_;
	int currentCompanyId_;
public:
	Laureat(int);
	void act();
};
#endif
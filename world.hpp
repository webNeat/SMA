#ifndef WORLD_HPP
#define WORLD_HPP
#include "company.hpp"
#include "school.hpp"
#include <vector>
#include <sstream>
#include "lib.hpp"
#include <fstream>
using namespace std;
class World {

	private:
		vector<Company> companies_;
		vector<School> schools_;

	public:
		string toString();
		void addSchool(School school);
		void addCompany(Company company);
		World();
		~World();
		//World(const World &s);
		//World& operator=(const World &s); 

		void save();
		void load();

	
};
#endif
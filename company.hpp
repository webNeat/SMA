#include "Internships.hpp"
#include "Laureat.hpp"
#include <vector>
using namespace std;

class Company : public Actor {
private:
    string name_;
    int numEmployees_;
    vector<Internship> internships_;
    vector<Laureat> laureats_;
    vector<Skill &> skills_;
public:
    Company(string name, int numEmployees);
    void addSkill(Skill & newSkill);
    void act();
    ~Company();
};
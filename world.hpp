#include <vector>
#include "generators.hpp"
using namespace std;

class World {
private:
    vector<Company> companies_;
    vector<School> schools_;
    vector<Statistic> stats_;
    vector<Actor *> actors_;
public:
    World();
    World(const World &);
    World & operator=(const World &);
    ~World();

    int newSkill(string name);
    int findSkill(string name);

    int newCompany(string name, int numEmployees);
    void addSkillToCompany(int skillId, int companyId);
    
    int newSchool(string name, int numStudents);
    void addSkillToSchool(int skillId, int schoolId, int level);

    void nextYear();
}
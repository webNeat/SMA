#include <vector>
using namespace std;

class School {
private:
    typedef vector<Skill &> Level;
    string name_;
    int numberStudentsPerYear_;
    vector<Level> levels_;
    vector<Student> students_;

public:
        School(string name, int numStudents);
        void addSkill(Skill & skill, int level);
        ~School();

};
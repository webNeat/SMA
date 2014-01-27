#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include <string>
#include <vector>
using namespace std;

typedef struct {
	string name;
} Skill;

typedef enum {
	STUDENT,
	LAUREAT,
	COMPANY,
	SCHOOL
} AgentType;

#endif
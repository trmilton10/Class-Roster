//
// Created by Tyler Milton on 8/13/22.
//
#ifndef CLASS_ROSTER_FINAL_DEGREE_H
#define CLASS_ROSTER_FINAL_DEGREE_H
#include <iostream>


/* REQUIREMENT C. Define an enumerated data type DegreeProgram for the degree programs
 * containing the data type values SECURITY, NETWORK, and SOFTWARE*/

enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

// Parallel Strings
static const std::string degreeProgramStrings[] = {
	"SECURITY", "NETWORK", "SOFTWARE"
};

#endif //CLASS_ROSTER_FINAL_DEGREE_H
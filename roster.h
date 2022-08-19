//
// Created by Tyler Milton on 8/13/22.
//

//#ifndef CLASS_ROSTER_FINAL_ROSTER_H
//#define CLASS_ROSTER_FINAL_ROSTER_H
#include "student.h"

class Roster {

public:

		int index = -1;
		const static int studentDataTable = 5;
		Student* classRosterArray[studentDataTable]; /* REQUIREMENT E1. Create an array of pointers, classRosterArray,
 																									*	to hold the data provided in the "studentDataTable" */

		/* parse function */
		void parse(std::string row);

		/* REQUIREMENT E3A. Define a function that sets the instance variables from D1 and updates the roster.

		 * update student information function */
		void add(std::string studentID, std::string firstName,
						 std::string lastName, std::string emailAddress, int age,
						 int day1, int day2, int day3, DegreeProgram degreeProgram);

		/* REQUIREMENT E3B. Define a function that removes students from the roster by student ID */
		bool removeStudentByID(std::string studentID);

		/* REQUIREMENT E3C. Define a function - printAll() that prints a complete tab-separated list of student data. */
		void printAll();

		/* REQUIREMENT E3D. Define a function that correctly prints a student's average days in the three courses. */
		void printAverageDays(std::string studentID);

		/* REQUIREMENT E3E. Define a function that verifies student email addresses and displays all invalid emails to
		 * the user. */
		void printInvalidEmail();

		/* REQUIREMENT E3F. Define a function that prints out student information for a degree program specified by an
		 * enumerated type. */
		void printByDegreeProgram(DegreeProgram dp);

		/* destructor function */
		~Roster();
};

// #endif //CLASS_ROSTER_FINAL_ROSTER_H
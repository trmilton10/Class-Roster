//
// Created by Tyler Milton on 8/13/22.
//

#include "roster.h"

// REQUIREMENT E2A. Parse each set of data identified in the data table and populate classRosterArray.
 void Roster::parse(std::string studentData) {

	size_t rhs = studentData.find(",");
	std::string ssID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	std::string sF = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	std::string sL = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	std::string sE = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sA = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = std::stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = std::stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = std::stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);

	DegreeProgram dp = SOFTWARE;
		if (studentData.at(lhs) == 'S' && studentData.at(lhs+1) == 'O') dp = SOFTWARE;
		else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') dp = SECURITY;
		else if (studentData.at(0) == 'N') dp = NETWORK;

		add(ssID, sF, sL, sE, sA, d1, d2, d3, dp);
}


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
								 int day1, int day2, int day3, DegreeProgram degreeProgram) {

	int dayArray[3] = {day1, day2, day3};

/* REQUIREMENT E2B. Add each student object to classRosterArray */
	classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age,
																							dayArray, degreeProgram);
}

/* REQUIREMENT E3B. Define a function that removes students from the roster by student ID */
bool Roster::removeStudentByID(std::string studentID) {
	{
		bool s = false;
		for (int i = 0; i <= Roster::index; i++)
		{
			if (classRosterArray[i]->getStudentID() == studentID) {
				s = true;
				if (i < studentDataTable - 1) {
					Student *temp = classRosterArray[i];
					classRosterArray[i] = classRosterArray[studentDataTable - 1];
					classRosterArray[studentDataTable - 1] = temp;
				}
				Roster::index--;
			}
		}
		if (s) {
			std::cout << studentID << " has been removed from roster!" << std::endl << std::endl;
			this->printAll();
		} else std::cout << studentID << " was not found." << std::endl << std::endl;;
		return 0;
	}
}

/* REQUIREMENT E3C. Define a function - printAll() that prints a complete tab-separated list of student data.
 * The function should loop through all students in the classRosterArray and call the print() function. */
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::index; i++) Roster::classRosterArray[i]->print(); /* <-----  E3C. loop and print()
		 																																															function. */
}

/* REQUIREMENT E3D.  Define a function that correctly prints a student's average days in the three courses. */
void Roster::printAverageDays(std::string studentID) {
	for (int i = 0; i <= Roster::index; i++) {
		if (classRosterArray[i]->getStudentID()== studentID) {
			std::cout << "Student ID: " << studentID << ", average days in course:  ";
			std::cout << (classRosterArray[i]->getDaysToCompleteCourse()[0]
									 + classRosterArray[i]->getDaysToCompleteCourse()[1]
									 + classRosterArray[i]->getDaysToCompleteCourse()[2])/3 << std::endl;
		}
	}
}

/* REQUIREMENT E3E. Define a function that verifies student email addresses and displays all invalid emails to
	 * the user. */
void Roster::printInvalidEmail()
	{
		bool x = false;
		for (int i = 0; i <= Roster::index; i++)
		{
			std::string email = (classRosterArray[i]->getEmailAddress());

			if ((email.find("@") == std::string::npos) || (email.find(" ") != std::string::npos)
			|| (email.find(".") == std::string::npos))
			{
				x = true;
				std::cout << email << " -" << '\t' << " is invalid." << std::endl;
			}
		}
		if (!x) std::cout << "There are no invalid emails." << std::endl;
	}

/* REQUIREMENT E3F. Define a function that prints out student information for a degree program specified by an
	 * enumerated type. */
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::index; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	std::cout << "Hasta la vista, baby" << std::endl;
	for (int i = 0; i < studentDataTable; i++) {
		delete classRosterArray[i];
	}
}

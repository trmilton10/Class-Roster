#include <iostream>
#include "roster.h"

int main() {

	/* REQUIREMENT F1. Print out to the screen the course title, programming language used, WGU student ID, and name */
	std::cout << "SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << std::endl
						<< "PROGRAMMING LANGUAGE: C++" << std::endl
						<< "WGU STUDENT ID: 010024543" << std::endl
						<< "NAME: Tyler Milton" << std::endl << std::endl
						<< "================================================" << std::endl << std::endl;

	const int numStudents = 5;

	/*REQUIREMENT F2. Create an instance of the Roster called classRoster.*/
	Roster classRoster;

	std::string studentData[] =
		{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Tyler,Milton,tmilt14@wgu.edu,24, 20, 40, 30,SOFTWARE" /* Modify the student table to include
																																			  your personal information as the last item. */
		};

	// REQUIREMENT F4

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
		{
			std::cout << "Displaying all students: " << std::endl;
			classRoster.printAll();
			std::cout << std::endl;
		}

		for (int i = 0; i < 3; i++) {
			std::cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl << std::endl;
			classRoster.printByDegreeProgram((DegreeProgram)i);
			std::cout << std::endl;
		}

		std::cout << "Displaying invalid email addresses: " << std::endl << std::endl;
		classRoster.printInvalidEmail();
		std::cout << std::endl;

		std::cout << "Displaying average days in course: " << std::endl;
		for (int i = 0; i < numStudents; i++) {
			classRoster.printAverageDays(classRoster.classRosterArray[i]->getStudentID());
		}
		std::cout << std::endl;

		std::cout << "Removing A3..." << std::endl;
		classRoster.removeStudentByID("A3"); std::cout <<  std::endl;

		std::cout << "Removing A3 again..." << std::endl;
		classRoster.removeStudentByID("A3");
	}

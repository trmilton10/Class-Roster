//
// Created by Tyler Milton on 8/13/22.
//

#ifndef CLASS_ROSTER_FINAL_STUDENT_H
#define CLASS_ROSTER_FINAL_STUDENT_H
#include <iostream>
#include "degree.h"

/* REQUIREMENT D1. Create the class Student in the files student.h which includes the following variables:
 * - student ID
 * - first name
 * - last name
 * - email address
 * - age
 * - array of # of days to complete course
 * - degree program */

class Student {

public:
		const static int dayArraySize = 3;

		/* REQUIREMENT D2D. Create a constructor using all of the input parameters provided in the table.

		default student constructor */
		Student();

		//full student constructor
		Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
						int daysToCompleteCourse[], DegreeProgram degreeProgram);

		//student destructor
		~Student();


		/* REQUIREMENT D2A. Create an accessor (getter) for each instance variable from D1.

		getters */
		std::string 	getStudentID();
		std::string 	getFirstName();
		std::string 	getLastName();
		std::string 	getEmailAddress();
		int						getAge();
		int						*getDaysToCompleteCourse();
		DegreeProgram 	getDegreeProgram();

		/* REQUIREMENT D2B. Create a mutator (setter) for each instance variable from D1.

		setters */
		void setStudentID(std::string studentID);
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setEmail(std::string emailAddress);
		void setAge(int age);
		void setDaysToCompleteCourse(int daysToComplete[]);
		void setDegree(DegreeProgram degreeProgram);

		//print header file constructor
		static void printHeader();

		/* REQUIREMENT D2E. Create a print() function to print specfic student data.

		 * prints student data */
		void print();


		/* REQUIREMENT D2C. All external access and changes to any instance variables must be done

		 * using accessor and mutator functions*/
private:
		std::string 		studentID, firstName, lastName, emailAddress;
		int							age;
		int							daysToCompleteCourse[dayArraySize];
		DegreeProgram		degreeProgram;


};

#endif //CLASS_ROSTER_FINAL_STUDENT_H
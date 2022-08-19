//
// Created by Tyler Milton on 8/13/22.
//

#include "student.h"

//default student constructor
Student::Student() {
	this->studentID = "DEFAULT";
	this->firstName = "DEFAULT ";
	this->lastName = "DEFAULT";
	this->emailAddress = "DEFAULT";
	this->age = 0;
	for (int i = 0; i < dayArraySize; i++){
			this->daysToCompleteCourse[i] = 0;
		}
	this->degreeProgram = DegreeProgram::NETWORK;
}

// full student constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
								 int daysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for(int i = 0; i < dayArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	this->degreeProgram = degreeProgram;
}

/* REQUIREMENT D2C. All external access and changes to any instance variables must be done
 * using accessor and mutator functions.

 * getters */
std::string Student::getStudentID() {
	return this->studentID;
}
std::string Student::getFirstName() {
	return this->firstName;
}
std::string Student::getLastName() {
	return this->lastName;
}
std::string Student::getEmailAddress() {
	return this->emailAddress;
}
int Student::getAge() {
	return this->age;
}
int* Student::getDaysToCompleteCourse() {
	return this->daysToCompleteCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

// setters
void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
	return;
}
void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
	return;
}
void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
	return;
}
void Student::setEmail(std::string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}
void Student::setAge(int age) {
	this->age = age;
	return;
}


void Student::setDaysToCompleteCourse(int daysToComplete[]) {
	for (int i = 0; i < dayArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
void Student::setDegree(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}

// Print header function
void Student::printHeader(){
	std::cout << "ID" << "\t"
		<< "FIRST" << "\t"
		<< "LAST" << "\t"
		<< "AGE" << "\t"
		<< "DAYSINCOURSE" << "\t"
		<< "DEGREE TYPE" << std::endl;
}

// Print student information function
void Student::print() {
	std::cout << this->getStudentID() << "\t";
	std::cout << this->getFirstName() << "\t";
	std::cout << this->getLastName() << "\t";
	std::cout << this->getAge()<< "\t";
	std::cout << "{" << this->getDaysToCompleteCourse()[0] << ",";
	std::cout << this->getDaysToCompleteCourse()[1] << ",";
	std::cout << this->getDaysToCompleteCourse()[2] << "}" "\t";
	std::cout << degreeProgramStrings[this->getDegreeProgram()] << "\n";
}

// destructor
Student::~Student(){
}


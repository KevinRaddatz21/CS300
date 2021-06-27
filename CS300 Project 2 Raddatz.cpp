//Kevin Raddatz
//CS300 Data Structures and Algorithms
//Project 2

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class course { //Creating Course Class

public:
	string courseCode; //Public Member variables
	string courseName; 
	vector<string> preRequisites; 

	string getCourseCode() {//Public Member Functions. Getters/Setters
		return courseCode; 
	}

	string getCourseName() {
		return courseName; 
	}

	vector<string> getpreRequisites() {
		return preRequisites; 
	}

	void setCourseCode(string courseCode) {
		courseCode = courseCode; 
	}
	void setCourseName(string name) {
		courseName = name;
	}

};

void printMenu() {
	cout << "What would you like to do?" << endl;
	cout << "1. Load data structure" << endl;
	cout << "2. Print course list" << endl;
	cout << "3. Print course" << endl;
	cout << "9. Exit" << endl;
}

void loadDataStructure(vector<course> courseList) {
	int NUMBER_OF_LINES = 8; //Temporary 
	fstream file; //File declaration
	file.open("ABCU_Advising_Program_Input.txt"); 
	string code; 
	string name; 

	for (int i = 0; i <= NUMBER_OF_LINES; i++) {
		getline(file, code,  ','); //Using Delimiting character to break up File
		courseList[i].courseCode.push_back(code); 

		getline(file, name, ',');
		courseList[i].courseCode.push_back(name);
	}
}
void printCourseList(vector<course> courseList) { //Printing out course list
	
	for (int i = 0; i <= size(courseList); i++) {
		cout << courseList[i].courseCode << " " << courseList[i].courseName << " "; 
		cout << courseList[i].preRequisites.at(0) << courseList[i].preRequisites.at(1) << endl;
	}


}
void printCourse(vector<course> courseList) {//Prints Information for a user specified course
	string userInput; //User enters the course code 
	cout << "Please Enter Course Code: " << endl; 
	cin >> userInput; 
	bool found = false; 

	for (int i = 0; i <= size(courseList); i++) {
		if (courseList[i].courseCode == userInput) {
			cout << courseList[i].courseCode << " ";
			cout << courseList[i].courseName << " " << courseList[i].preRequisites.at(0) << " " << courseList[i].preRequisites.at(1) << endl;
			found = true;
			break;
		}
		else if(i == size(courseList) && found == false) {
			cout << "ERROR: Course Code Not Found"; 
		}
		else {
			continue; 
		}
	}


}


int main() { //Main Function 
	int selection = 0;
	cout << "Welcome to the course planner." << endl;
	vector<course> courseList; 
	

	while (selection != 9) {//Switch Statement will execute as long as the exit key (9) isn't pressed

		printMenu(); //Calling menu function and taking user input
		cin >> selection;

		if (selection == 1 || selection == 2 || selection == 3) { //Logic to handle Valid/invalid inputs

			switch (selection) {//Switch Statements will take input and make decision on what function to call based on user input

			case 1:
				loadDataStructure(courseList);
				break;

			case 2:
				printCourseList(courseList);
				break;

			case 3:
				printCourse(courseList);
				break;
			}
		}
		else {//Else Statement handles invalid user inputs
			cout << "Invalid Input. Please Try Again" << endl;
		}
	}
	return 0;
}
#include <iostream>
#include <string>

#include "datastruct.h"
#include "parcingutil.h"


student_info* requestStudentInfo(int length) {
	std::string studentInfo;
	student_info* arr = new student_info[length];

	for(int i = 0; i < length; i++) {
		std::getline(std::cin, studentInfo);
		student_info* aStudentInfo = studentInfoParser(studentInfo);
		arr[i].studentID = aStudentInfo->studentID;
		arr[i].nameOfStduent = aStudentInfo->nameOfStduent;
		delete aStudentInfo;
	}

	
	
	return arr;
}

grade_artifact* requestGradeArtifact(int length) {
	std::string possibleScoreStr;
	std::getline(std::cin, possibleScoreStr);
	
	std::string weightStr;
	std::getline(std::cin, weightStr);

	grade_artifact* pArr = new grade_artifact[length];
	int* possibleGrades = generalizedParser(length, possibleScoreStr); 
	int* weights = generalizedParser(length, weightStr);

	for(int i = 0; i < length; i++) {
		pArr[i].possibleScore = possibleGrades[i];
		pArr[i].weight = weights[i];
	}

	delete[] possibleGrades;
	delete[] weights;

	return pArr;

}



int main() {

	// Part1
	std::string numStr = "";
	int numberOfElement = 0;
	getline(std::cin, numStr);
	numberOfElement = stringToInteger(numStr);//atoi(numStr.c_str());

	grade_artifact* pGradeArtifacts = requestGradeArtifact(numberOfElement);

	for(int i = 0; i < numberOfElement; i++) {
		std::cout << "Possible Score: " << pGradeArtifacts[i].possibleScore 
			<< "Weight: " << pGradeArtifacts[i].weight << std::endl;
	}

	//Part2
	std::string numberOfStudentsStr = "";
	int numberOfStudents = 0;
	getline(std::cin, numberOfStudentsStr);
	numberOfStudents = stringToInteger(numberOfStudentsStr);

	student_info* pStudentInfos = requestStudentInfo(numberOfStudents);


	for(int i = 0; i < numberOfStudents; i++) {
		std::cout << "Student ID: " << pStudentInfos[i].studentID << " Student Name: " << pStudentInfos[i].nameOfStduent << std::endl; 
	}

	delete[] pGradeArtifacts;
	delete[] pStudentInfos;

	getchar();
	


	return 0;
}


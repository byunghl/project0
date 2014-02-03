#include <iostream>
#include <string>

#include "input_requester.h"
#include "parcingutil.h"
#include "evaluation.h"
#include "output.h"


int main() {

	// Part1
	std::string numStr = "";
	unsigned int numberOfGradeArtifactElement = 0;
	getline(std::cin, numStr);
	numberOfGradeArtifactElement = stringToInteger(numStr);

	grade_artifact* pGradeArtifacts = requestGradeArtifact(numberOfGradeArtifactElement);

	/*
	for(unsigned int i = 0; i < numberOfGradeArtifactElement; i++) {
		std::cout << "Possible Score: " << pGradeArtifacts[i].possibleScore 
			<< "Weight: " << pGradeArtifacts[i].weight << std::endl;
	}
	*/
	
	
	
	//Part2
	std::string numberOfStudentsStr = "";
	unsigned int numberOfStudents = 0;
	getline(std::cin, numberOfStudentsStr);
	numberOfStudents = stringToInteger(numberOfStudentsStr);

	student_info* pStudentInfos = requestStudentInfo(numberOfStudents);

	/*
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		std::cout << "Student ID: " << pStudentInfos[i].studentID << " Student Name: " << pStudentInfos[i].nameOfStduent << std::endl; 
	}
	*/

	//Part3
	std::string numberOfRawScoresStr = "";
	std::getline(std::cin, numberOfRawScoresStr);
	unsigned int numberOfRawScores = stringToInteger(numberOfRawScoresStr);
	
	requestRawScores(numberOfRawScores, numberOfGradeArtifactElement, pStudentInfos);
	
	/*
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		int* pTemp = pStudentInfos[i].rawScores;
		for(unsigned int j = 0; j < numberOfGradeArtifactElement; j++) {
			std::cout << pTemp[j] << std::endl;
		}
	}
	*/

	// evaluate total score
	setTotalScore(pGradeArtifacts, numberOfGradeArtifactElement, pStudentInfos, numberOfStudents);
	
	/*
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		std::cout << "Student ID: " << pStudentInfos[i].studentID << "  Total Score:" << pStudentInfos[i].totalScore << std::endl;
	}
	*/
	

	// print total score
	printTotalScore(pStudentInfos, numberOfStudents);
	
	//Part4
	std::string numberOfCutPointStr = "";
	std::getline(std::cin, numberOfCutPointStr);
	unsigned int numberOfCutsetRange = 4;
	unsigned int numberOfCutPoint = (unsigned int)stringToInteger(numberOfCutPointStr);
	cutset* pCutsets = requestCutSetPoints(numberOfCutPoint, numberOfCutsetRange, pStudentInfos, numberOfStudents);
	/*
	for(unsigned int i = 0; i < numberOfCutPoint; i++){
		for(unsigned int j = 0; j < numberOfCutsetRange; j++) {
			std::cout << pCutsets[i].aCutsets[j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	

	
	

	// Clear Memory
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		delete[] pStudentInfos[i].rawScores;
	}
	for(unsigned int i = 0; i < numberOfCutPoint; i++) {
		delete[] pCutsets[i].aCutsets;
	}

	delete[] pCutsets; 

	delete[] pGradeArtifacts;
	delete[] pStudentInfos;
	// END of Memory Clearing

	getchar();
	


	return 0;
}


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

void requestRawScores(int length, int numberOfGradeArtifact, student_info* stdInfos ) {
	std::string inputedStr = "";
	int* pPointsArr = NULL;
	//int lengthOfPointsPart = length-1; 사용안됨. 정검필요.
	for(int i = 0; i < length; i++) {
		std::getline(std::cin, inputedStr); //한줄 받기
		int firstEmptyOffset = inputedStr.find(" ", 0); 
		std::string idPartStr = inputedStr.substr(0, firstEmptyOffset); // 아이디파트
		int idNo = stringToInteger(idPartStr);
		std::string pointsParts = inputedStr.substr(firstEmptyOffset+1); // 포인트파트
	
		pPointsArr = generalizedParser(numberOfGradeArtifact, pointsParts); // 여기까지 메모리 릭 없음.
		
		for(int j = 0; j < length; j++) {
			if(idNo == stdInfos[j].studentID) { 
				stdInfos[j].rawScores = new int[numberOfGradeArtifact]; // 메모리정검!
				for(int index=0; index < numberOfGradeArtifact; index++)
				{
					stdInfos[j].rawScores[index] = pPointsArr[index]; 
				}
			}
		}
		
		delete[] pPointsArr;
	}

	

}

grade_artifact* requestGradeArtifact(int length) {
	std::string possibleScoreStr;
	std::getline(std::cin, possibleScoreStr);
	
	std::string weightStr;
	std::getline(std::cin, weightStr);

	grade_artifact* pArr = new grade_artifact[length];
	int* pPossibleGrades = generalizedParser(length, possibleScoreStr); 
	int* pWeights = generalizedParser(length, weightStr);

	for(int i = 0; i < length; i++) {
		pArr[i].possibleScore = pPossibleGrades[i];
		pArr[i].weight = pWeights[i];
	}

	delete[] pPossibleGrades;
	delete[] pWeights;

	return pArr;

}



int main() {

	// Part1
	std::string numStr = "";
	unsigned int numberOfGradeArtifactElement = 0;
	getline(std::cin, numStr);
	numberOfGradeArtifactElement = stringToInteger(numStr);//atoi(numStr.c_str());

	grade_artifact* pGradeArtifacts = requestGradeArtifact(numberOfGradeArtifactElement);

	for(int i = 0; i < numberOfGradeArtifactElement; i++) {
		std::cout << "Possible Score: " << pGradeArtifacts[i].possibleScore 
			<< "Weight: " << pGradeArtifacts[i].weight << std::endl;
	}
	
	//Part2
	std::string numberOfStudentsStr = "";
	unsigned int numberOfStudents = 0;
	getline(std::cin, numberOfStudentsStr);
	numberOfStudents = stringToInteger(numberOfStudentsStr);

	student_info* pStudentInfos = requestStudentInfo(numberOfStudents);

	for(int i = 0; i < numberOfStudents; i++) {
		std::cout << "Student ID: " << pStudentInfos[i].studentID << " Student Name: " << pStudentInfos[i].nameOfStduent << std::endl; 
	}

	//Part3
	std::string numberOfRawScoresStr = "";
	std::getline(std::cin, numberOfRawScoresStr);
	unsigned int numberOfRawScores = stringToInteger(numberOfRawScoresStr);
	
	requestRawScores(numberOfRawScores, numberOfGradeArtifactElement, pStudentInfos);

	//int* pTemp = NULL;
	
	for(int i = 0; i < numberOfStudents; i++) {
		int* pTemp = pStudentInfos[i].rawScores;
		for(int j = 0; j < numberOfGradeArtifactElement; j++) {
			std::cout << pTemp[j] << std::endl;
		}
	}
	


	// Memory clear;
	for(int i = 0; i < numberOfStudents; i++) {
		delete[] pStudentInfos[i].rawScores;
	}

	//delete[] pTemp;
	delete[] pGradeArtifacts;
	delete[] pStudentInfos;
	
	getchar();
	


	return 0;
}


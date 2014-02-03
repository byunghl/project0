#include "input_requester.h"
#include "parcingutil.h"
#include "output.h"
#include <iostream>
#include <string>

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

cutset* requestCutSetPoints(unsigned int length, unsigned int numberOfCusetRange, student_info* pStdInfo, unsigned int numberOfStudent) {

	std::string aCutSetPointsStr = "";
	cutset* arr = new cutset[length];
	
	for(unsigned int i = 0; i < length; i++) {
		std::getline(std::cin, aCutSetPointsStr);
		arr[i].aCutsets = generalizedPaserForDouble(numberOfCusetRange, aCutSetPointsStr);
		printCutpint(i+1, arr[i].aCutsets, pStdInfo, numberOfStudent ); // OUTPUT FUNCTION CALL
	}
	
	return arr;
}

void requestRawScores(int length, int numberOfGradeArtifact, student_info* pStdInfos ) {
	std::string inputedStr = "";
	int* pPointsArr = NULL;
	
	for(int i = 0; i < length; i++) {
		std::getline(std::cin, inputedStr); //한줄 받기
		int firstEmptyOffset = inputedStr.find(" ", 0); 
		std::string idPartStr = inputedStr.substr(0, firstEmptyOffset); // 아이디파트
		int idNo = stringToInteger(idPartStr);
		std::string pointsParts = inputedStr.substr(firstEmptyOffset+1); // 포인트파트
	
		pPointsArr = generalizedParser(numberOfGradeArtifact, pointsParts); // 여기까지 메모리 릭 없음.
		
		for(int j = 0; j < length; j++) {
			if(idNo == pStdInfos[j].studentID) { 
				pStdInfos[j].rawScores = new int[numberOfGradeArtifact]; // 메모리정검!
				for(int index=0; index < numberOfGradeArtifact; index++)
				{
					pStdInfos[j].rawScores[index] = pPointsArr[index]; 
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
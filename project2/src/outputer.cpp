#include "output.h"
#include "evaluation.h"
#include <iostream>
#include <string>

void printTotalScore(student_info* pStdInfo, unsigned int numberOfStudent) {

	std::cout << "TOTAL SCORES" << std::endl;
	for(unsigned int i = 0; i < numberOfStudent; i++) {
		std::cout <<  pStdInfo[i].studentID << " " << pStdInfo[i].nameOfStduent << " " << pStdInfo[i].totalScore << std::endl;
	}

}


void printCutpint(int number, double* pCutset, student_info* pStdInfo, unsigned int numberOfStudent ) {

	setFinalLetterGrade(pCutset, pStdInfo, numberOfStudent);

	std::cout << "CUTPOINT SET " << number << std::endl;
	for(unsigned int i = 0; i < numberOfStudent; i++) {
		std::cout << pStdInfo[i].studentID << " " << pStdInfo[i].nameOfStduent << " " << pStdInfo[i].finalLetterGrade;
	}
	
}
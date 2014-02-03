#include "evaluation.h"

#include <iostream>

void setTotalScore(grade_artifact* pGradeArtifact, unsigned int numberOfGradeArtifact, student_info* pStdInfo, unsigned int numberOfStudents) {
	
	double totalScore = 0.0;
	
	// access to each student's record
	for(unsigned int i = 0; i < numberOfStudents; i++) {
		
		int* tempRawScores = pStdInfo[i].rawScores; // holds a student's raw score info
		
		for(unsigned int scoreCounter = 0; scoreCounter < numberOfGradeArtifact; scoreCounter++) {
			
			int aScore = tempRawScores[scoreCounter];

			totalScore += getEachScaledScore(aScore, pGradeArtifact[scoreCounter]);

		}

		pStdInfo[i].totalScore = totalScore;
		totalScore = 0.0;
	}

}


double getEachScaledScore(int score, grade_artifact gradeArtifact) {

	//std::cout << "score: " << score << std::endl;
	//std::cout << "possible: " << gradeArtifact.possibleScore << std::endl;
	//std::cout << "weight: " << gradeArtifact.weight << std::endl;
	//std::cout << "total: " << (double)score / (double)gradeArtifact.possibleScore * (double)gradeArtifact.weight << std::endl;
	
	return (double)score / (double)gradeArtifact.possibleScore * (double)gradeArtifact.weight;

}

char letterGradeCalculator(double* pCutset, double totalScore) {
	char letterGrade = ' ';
	if(totalScore >= pCutset[0]) 
		letterGrade = 'A';
	else if(totalScore >= pCutset[1])
		letterGrade = 'B';
	else if(totalScore >= pCutset[2])
		letterGrade = 'C';
	else
		letterGrade = 'F';

	return letterGrade;
}

void setFinalLetterGrade(double* pCutset, student_info* pStdInfo, unsigned int numberOfStudent) {

	for(int i = 0; i < numberOfStudent;i++) {	
		pStdInfo[i].finalLetterGrade = letterGradeCalculator(pCutset, pStdInfo[i].totalScore);
	}

}


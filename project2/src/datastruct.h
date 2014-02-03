#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <string>

struct grade_artifact {
	int possibleScore;
	int weight;
};


struct student_info {
	unsigned int studentID;
	std::string nameOfStduent;
	int* rawScores;
	double totalScore;
	char finalLetterGrade;
};


struct cutset {
	double* aCutsets;

};

#endif

#ifndef EVALUATION_H
#define EVALUATION_H

#include "datastruct.h"

void setTotalScore(grade_artifact* pGradeArtifact, unsigned int numberOfGradeArtifact, student_info* pStdInfo, unsigned int numberOfStudents);
double getEachScaledScore(int score, grade_artifact gradeArtifact);
void setFinalLetterGrade(double* pCutset, student_info* pStdInfo, unsigned int numberOfStudent);




#endif
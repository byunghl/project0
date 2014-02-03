#ifndef INPUT_REQUEST_H
#define INPUT_REQUEST_H

#include "datastruct.h"

student_info* requestStudentInfo(int length);

cutset* requestCutSetPoints(unsigned int length, unsigned int numberOfCusetRange, student_info* pStdInfo, unsigned int numberOfStudent);

void requestRawScores(int length, int numberOfGradeArtifact, student_info* pStdInfos );

grade_artifact* requestGradeArtifact(int length);

#endif
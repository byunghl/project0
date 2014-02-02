#ifndef PARCINGUTIL_H
#define PARCINGUTIL_H

#include "datastruct.h"
#include <string>

int stringToInteger(std::string str);
double stringToDouble(std::string str);
int* generalizedParser(int length, std::string str);
double* generalizedPaserForDouble(int numberOfGradeArtifact, std::string str);
student_info* studentInfoParser(std::string str);





#endif
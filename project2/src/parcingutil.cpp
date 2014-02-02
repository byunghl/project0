#include "parcingutil.h"

int stringToInteger(std::string str) {
	return atoi(str.c_str());
}

double stringToDouble(std::string str){
	return atof(str.c_str());
}

int* generalizedParser(int length, std::string str) {
	
	int* pValues = new int[length];
	
	int numberOfEmptyChar = length - 1;
	int start = 0;
	int current = -1;
	int previous = 0;
	int counter = 0;
	std::string temp = "";

	if(numberOfEmptyChar == 0) {
		temp = str.substr(start);
		pValues[0] = stringToInteger(temp);
	} else {
		for(int i = 0; i < numberOfEmptyChar; i++) {

			current = str.find(" ", start);
			// Later delete print part under it.
			if((current !=-1) && i==0 ) {
				temp = str.substr(start, current) ;
				pValues[i] = stringToInteger(temp);
				previous = current;
				start = current+1;
				counter++;
			} else {
				temp = str.substr(start, (current-previous));
				pValues[i] = stringToInteger(temp);
				previous = current;
				start = current+1;
				counter++;
			}
			if(i == (numberOfEmptyChar - 1) ) {
				temp = str.substr(start);
				pValues[i+1] = stringToInteger(temp);
			}
		}
	}
	
	return pValues;

}

double* generalizedPaserForDouble(int numberOfGradeArtifact, std::string str) {

	double* pValues = new double[numberOfGradeArtifact];
	
	int numberOfEmptyChar = numberOfGradeArtifact - 1;
	int start = 0;
	int current = -1;
	int previous = 0;
	int counter = 0;
	std::string temp = "";

	if(numberOfEmptyChar == 0) {
		temp = str.substr(start);
		pValues[0] = stringToDouble(temp);
	} else {
		for(int i = 0; i < numberOfEmptyChar; i++) {

			current = str.find(" ", start);
			// Later delete print part under it.
			if((current !=-1) && i==0 ) {
				temp = str.substr(start, current) ;
				pValues[i] = stringToDouble(temp);
				previous = current;
				start = current+1;
				counter++;
			} else {
				temp = str.substr(start, (current-previous));
				pValues[i] = stringToDouble(temp);
				previous = current;
				start = current+1;
				counter++;
			}
			if(i == (numberOfEmptyChar - 1) ) {
				temp = str.substr(start);
				pValues[i+1] = stringToDouble(temp);
			}
		}
	}
	
	return pValues;

}



student_info* studentInfoParser(std::string str) {
	int emptyCharOffset = str.find(" ", 0);
	std::string studentIdStr = str.substr(0, emptyCharOffset);
	std::string studentName = str.substr(emptyCharOffset);
	student_info* aStudentInfo = new student_info;
	aStudentInfo->studentID = atoi(studentIdStr.c_str());
	aStudentInfo->nameOfStduent = studentName;

	return aStudentInfo;
}



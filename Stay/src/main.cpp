#include "Project1Core.h"

int main() {

    // Program Start Here!
    
    
    Location startLocation = getFirstLineInput();
    int numberOfTargetLocation = getSecondLineInput();
    std::vector<Location> targetLocations = getThirdLineInput(numberOfTargetLocation);
    std::vector<Location> resultOfComputation = getComputedResult(startLocation, targetLocations);
    printResult(startLocation, resultOfComputation);
    

    std::cout << findNameOfLocationPart("33.9425/N 118.4081/W LA Airport");


    /* TEST CASE
    Latitude testStartLatitude("33.9425", "N");
    Longitude testStartLongitude("118.4081", "W");
    Location testStartLocation(testStartLatitude, testStartLongitude, "Los Angeles International Airport");
    int testNumber = 3;

    Latitude test1lat("20.8987", "N");
    Longitude test1lon("156.4305", "W");
    Location test1(test1lat, test1lon, "Kahului Airport");

    Latitude test2lat("47.4647", "N");
    Longitude test2lon("8.5492", "E");
    Location test2(test2lat, test2lon, "Zurich Airport");

    Latitude test3lat("23.4356", "S");
    Longitude test3lon("46.4731", "W");
    Location test3(test3lat, test3lon, "Sao Paolo-Guarulhos International Airport");
    
    std::vector<Location> targets;
    targets.resize(3);

    targets[0] = test1;
    targets[1] = test2;
    targets[2] = test3;

    std::vector<Location> resultOfComputation = getComputedResult(testStartLocation, targets);
    //std::string str = testStartLocation.getLatitude().getCoordinateStr();
    //std::cout << str << std::endl;
    printResult(testStartLocation, resultOfComputation);
    */
    
    /*
    for(int i = 0; i < resultOfComputation; i++) {
        std::cout << i << std::endl;
    }
    */
    
    // END OF PROGRAM


    

    return 0;
}

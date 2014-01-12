/*  Author: Byung Ho Lee
**  Student ID#: 60626811
**  Start Date: 1/11/2014
**  Due Date: 1/17/2014
**  Project#0 
**  Version: 0.12 
*/

#include <iostream>
#include <fstream>
#include <string>

// FUNCTION DECLARTION
void setFirstName(std::string& firstName);
void setLastName(std::string& lastName);
void setEmailAddress(std::string& eMail);
void setPersonInfo(std::string& firstName, std::string& lastName, std::string& email) ;
void modifyTemplate(std::string& templateStr, std::string& firstName, std::string& lastName, std::string email) ;
void replaceWord(std::string& templateStr, int start, int range, std::string target, std::string word);
int getPosition(std::string templateStr, std::string keyword);
bool hasMore(std::string templateStr, int start, std::string word);
void showMessage(std::string message);

// END OF FUNCTION DECLARTION


// FUNCTION DEFINITION

// Function setFirstName: Get first name from User.
void setFirstName(std::string& firstName){
    std::cout << "Input your First Name: ";
    std::getline(std::cin, firstName);
}

// Function setLastName: get first name from user.
void setLastName(std::string& lastName){
    std::cout << "Input your Last Name: ";
    std::getline(std::cin, lastName);
}

// Function setEmailAddress: get email from user.
void setEmailAddress(std::string& eMail){
    std::cout << "Input your e-mail address: ";
    std::getline(std::cin, eMail);

    std::cout << std::endl << std::endl;
}

void setPersonInfo(std::string& firstName, std::string& lastName, std::string& email) {
   setFirstName(firstName);
   setLastName(lastName);
   setEmailAddress(email);
}

void modifyTemplate(std::string& templateStr, std::string& firstName, std::string& lastName, std::string email) {

    std::string varFirstName="$FIRST_NAME";
    std::string varLastName="$LAST_NAME";
    std::string varEmail="$EMAIL";

    int lengthOfVarFirstName = varFirstName.length();
    int lengthOfVarLastName = varLastName.length();
    int lengthOfVarEmail = varEmail.length();

    replaceWord(templateStr, getPosition(templateStr, varFirstName), lengthOfVarFirstName, varFirstName, firstName);
    replaceWord(templateStr, getPosition(templateStr, varLastName), lengthOfVarLastName, varLastName, lastName);
    replaceWord(templateStr, getPosition(templateStr, varEmail), lengthOfVarEmail, varEmail, email);
}

int getPosition(std::string templateStr, std::string keyword) {
    return templateStr.find(keyword); 
}

void replaceWord(std::string& templateStr, int start, int range, std::string target,  std::string word) {
   
    int newStart = start + range;
    
    templateStr.replace(start, range, word);
    
    while(hasMore(templateStr, newStart, target)){
        int location = getPosition(templateStr, target);
        templateStr.replace(location, range, word);
        newStart = newStart + range;
    }
}

bool hasMore(std::string templateStr, int start, std::string word) {
    int temp = templateStr.find(word, start);
    if(temp == -1){
        return false;
    }else{
        return true;
    }
}

void showMessage(std::string message) {
    std::cout << message;
}

// MAIN FUNCTION
int main()
{
    std::string firstName = "";
    std::string lastName = "";
    std::string emailAddress= "";
    
    std::string line = "";
    std::string templateStr = "";
    std::ifstream templateFile("template.txt");
    
    if(templateFile.is_open()){
        while(std::getline(templateFile, line)) {
           // std::cout << line << '\n';
           templateStr += line;
           templateStr = templateStr + "\n";
        }
    }else {
        std::cout << "Unable to open file";
    }

    setPersonInfo(firstName, lastName, emailAddress);
        
    modifyTemplate(templateStr, firstName, lastName, emailAddress); 
  
    showMessage(templateStr);

    return 0;
}


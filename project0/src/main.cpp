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
void replaceWord(std::string& templateStr, int start, int range, std::string word);
int getPosition(std::string templateStr, std::string keyword);
// END OF FUNCTION DECLARTION


// FUNCTION DEFINITION
void setFirstName(std::string& firstName){
    std::cout << "Input your First Name: ";
    std::getline(std::cin, firstName);
}

void setLastName(std::string& lastName){
    std::cout << "Input your Last Name: ";
    std::getline(std::cin, lastName);
}

void setEmailAddress(std::string& eMail){
    std::cout << "Input your e-mail addres: ";
    std::getline(std::cin, eMail);
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

    replaceWord(templateStr, getPosition(templateStr, varFirstName), lengthOfVarFirstName, firstName);
    replaceWord(templateStr, getPosition(templateStr, varLastName), lengthOfVarLastName, lastName);
    replaceWord(templateStr, getPosition(templateStr, varEmail), lengthOfVarEmail, email);
}

int getPosition(std::string templateStr, std::string keyword) {
    return templateStr.find(keyword); 
}

void replaceWord(std::string& templateStr, int start, int range, std::string word) {
    templateStr.replace(start, range, word);
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
        }
    }else {
        std::cout << "Unable to open file";
    }

    setPersonInfo(firstName, lastName, emailAddress);
        
    modifyTemplate(templateStr, firstName, lastName, emailAddress); 

    //WORK!! getFirstName(firstName);
    // getLastName(lastName);
    // getEmailAddress(emailAddress);

    std::cout << templateStr;
    
    /* TODO: NEED TO DO MODULATION PROCESS
    std::cout <<"Your first name is: " << firstName << std::endl
            << "Last name is : " << lastName <<  std::endl
            << "Email : " << emailAddress << std::endl;
    */

    return 0;
}


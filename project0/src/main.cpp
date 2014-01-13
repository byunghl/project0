/*  Author: Byung Ho Lee
**  Student ID#: 60626811
**  Start Date: 1/11/2014
**  Due Date: 1/17/2014
**  Project#0 
**  Version: 0.12 
*/

#include <iostream>
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
bool isNumber(const char Character);
bool isCharacter(const char Character);
bool isValidEmailAddress(std::string email);

std::string getTemplate();

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
    bool isNotValid = true;
    while(isNotValid){
        std::cout << "Input your e-mail address: ";
        std::getline(std::cin, eMail);
        if(isValidEmailAddress(eMail))
            isNotValid = false;
        else
            std::cout << "Invalid e-mail adress. Please input valid one.\n";
    }
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
bool isCharacter(const char Character) {
    return ( (Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z') );
}

bool isNumber(const char Character) {
    return ( Character >= '0' && Character <= '9');
}

bool isValidEmailAddress(std::string email) {

    if(email.length() == 0) // if empty string
        return false;
    if(!isCharacter(email[0])) // if first letter of email string is not a character
        return false;
    
    int atOffset = -1;
    int dotOffset = -1;

    for(int i = 0; i < email.length(); i++) {
        if(email[i] == '@')
            atOffset = i;
        else if(email[i] == '.')
            dotOffset = i;
    }
    
    if( (atOffset == -1) || (dotOffset == -1) ) 
        return false;
    if(atOffset > dotOffset)
        return false;
    if(dotOffset >= email.length()-1)
        return false;
    
    return true;
       

}

void showMessage(std::string message) {
    std::cout << message;
}

std::string getTemplate() {

    std::string templateStr = "From: Customer Service <customer_service@ics45c.com>\n"
    "To: $FIRST_NAME $LAST_NAME <$EMAIL>\n"
    "Subject: ICS45C appreciates your business!\n\n"
    "Dear $FIRST_NAME $LAST_NAME:\n\n"
    "We are writing today to thank you for your business, and to invite you\n"
    "to contact us if you have any comments and concerns about your recent\n"
    "order. If so, please email us at customer_services@ics45c.com and we\n"
    "would be delighted to discuss them with you.\n\n\n\n"
    "Many Thanks,\n\nICS45C Customer Service Team\n";

    return templateStr;
}

// MAIN FUNCTION
int main()
{
    std::string firstName = "";
    std::string lastName = "";
    std::string emailAddress= "";
    
    std::string templateStr = getTemplate();

    setPersonInfo(firstName, lastName, emailAddress);

    modifyTemplate(templateStr, firstName, lastName, emailAddress); 
  
    showMessage(templateStr);

    

    return 0;
}


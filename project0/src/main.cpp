/*  Author: Byung Ho Lee
**  Student ID#: 60626811
**  Date: 
**  Project 
**  Version: 0.11 
*/

#include <iostream>
#include <cstring>

void getFirstName(std::string& firstName){
    std::cout << "Input your First Name: ";
    std::getline(std::cin, firstName);
}

void getLastName(std::string& lastName){
    std::cout << "Input your Last Name: ";
    std::getline(std::cin, lastName);
}

void getEmailAddress(std::string& eMail){
    std::cout << "Input your e-mail addres: ";
    std::getline(std::cin, eMail);
}

int main()
{
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
   
    getFirstName(firstName);
    getLastName(lastName);
    getEmailAddress(emailAddress);

    std::cout <<"Your first name is: " << firstName << std::endl
            << "Last name is : " << lastName <<  std::endl
            << "Email : " << emailAddress << std::endl;


    return 0;
}


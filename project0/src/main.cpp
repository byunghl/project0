#include <iostream>
#include <cstring>

int main()
{
    std::string firstName;
    std::string lastName;

    std::cout << "Input your First Name: ";
    std::getline(std::cin, firstName);

    std::cout << "Input your Last Name: ";
    std::getline(std::cin, lastName);
    
    std::cout <<"Your first name is: " << firstName << std::endl
            << "Last name is : " << lastName <<  std::endl;


    return 0;
}


#include <iostream>

void foo(int& i) {

    int a = i;
    a++;

}

int main()
{
    int i = 3;
    foo(i);

    std::cout << i  << std::endl;
    
    return 0;
}


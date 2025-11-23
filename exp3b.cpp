#include <iostream>
#include "exp3.h"
using namespace std;

int main() {
    string str;
    char choice='y';

    while(choice=='y' || choice=='Y'){
        cout<<"Enter a string: ";
        cin>>str;
        checkConst(str);

        cout<<"Want to enter another string? y/n: ";
        cin>>choice;
    }
    
    return 0;
}
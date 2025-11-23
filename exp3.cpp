#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isIntegerConst(string s){
    int i=0;
    if(s[0]=='+' || s[0]=='-'){
        i=1;
    }
    if(i==s.size()){
        return false;
    }
    while(i<s.size()){
        if(!isdigit(s[i])){
            return false;
        }
        i++;
    }
    return true;
}

bool isFloatConst(string s){
    bool decimal=false;
    bool digit=false;
    int i=0;
    if(s[0]=='+' || s[0]=='-'){
        i=1;
    }
    while(i<s.size()){
        if(isdigit(s[i])){
            digit=true;
        }
        else if(s[i]=='.' && !decimal){
            decimal=true;
        }
        else{
            return false;
        }
        i++;
    }
    return (digit&&decimal);
}

bool isCharConst(string s){
    return (s.size()==3 && s[0]=='\'' && s[2]=='\'');
}

bool isBooleanConst(string s){
    return (s=="true" || s=="false");
}

void checkConst(string s){
    if (isIntegerConst(s))
        cout << s << " is an Integer Constant." << endl;
    else if (isFloatConst(s))
        cout << s << " is a Floating Constant." << endl;
    else if (isCharConst(s))
        cout << s << " is a Character Constant." << endl;
    else if (isBooleanConst(s))
        cout << s << " is a Boolean Constant." << endl;
    else
        cout << s << " is not a Constant." << endl;
}
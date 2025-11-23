#include <iostream>
#include <string>
using namespace std;

bool isKeyword(string str){
    string keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "inline", "int", "long", "register", "return", "short",
        "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "while", "and", "bool", "catch", "class", "false", "friend",
        "mutable", "namespace", "new",  "not",  "nullptr",
        "operator", "or", "private", "protected", "public", "template", "this",
        "throw", "true", "try", "typename", "using", "virtual", "xor"
    };

    for(string k:keywords){
        if(str==k){
            return true;
        }
    }
    return false;
}

int main() {
    string str;
    cout<<"Enter a word: ";
    cin>>str;
    if(isKeyword(str)){
        cout<<str<<" is a C++ keyword"<<endl;
    }
    else{
        cout<<str<<" is not a C++ keyword"<<endl;
    }
    
    return 0;
}
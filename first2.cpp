#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of productions: ";
    cin>>n;

    map<char,vector<string>> grammar;
    map<char,set<char>> firstSet;

    cout<<"Enter Productions: "<<endl;
    for(int i=0;i<n;i++){
        char lhs;
        string arrow,rhs;
        cin>>lhs>>arrow>>rhs;
        grammar[lhs].push_back(rhs);
    }

    for(auto &rule:grammar){
        char nonTerminal=rule.first;
        for(string prod:rule.second){
            char firstChar=prod[0];
            firstSet[nonTerminal].insert(firstChar);
        }
    }

    for(auto &it:firstSet){
        cout<<"FIRST("<<it.first<<") = {";
        for(char c:it.second){
            cout<<c<<" ";
        }
        cout<<"}"<<endl;
    }

    return 0;
}
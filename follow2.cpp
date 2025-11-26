#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<char,vector<string>> grammar;
map<char,set<char>> followSet;

int main() {
    int n;
    cout<<"Enter number of productions: ";
    cin>>n;

    cout<<"Enter Productions: "<<endl;
    for(int i=0;i<n;i++){
        char lhs;
        string arrow,rhs;
        cin>>lhs>>arrow>>rhs;
        grammar[lhs].push_back(rhs);
    }

    char startSymbol=grammar.begin()->first;
    followSet[startSymbol].insert('$');

    for(auto &rule:grammar){
        char lhs=rule.first;

        for(string prod:rule.second){
            for(int i=0;i<prod.length();i++){
                char B=prod[i];

                if(isupper(B)){
                    if(i+1<prod.length()){
                        followSet[B].insert(prod[i+1]);
                    }
                    else{
                        for(char c:followSet[lhs]){
                            followSet[B].insert(c);
                        }
                    }
                }
            }
        }
    }

    for(auto &it:followSet){
        cout<<"FOLLOW("<<it.first<<") = { ";
        for(char c:it.second){
            cout<<c<<" ";
        }
        cout<<"}"<<endl;
    }

    return 0;
}
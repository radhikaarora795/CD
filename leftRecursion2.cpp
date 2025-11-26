#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string s,char delimiter){
    vector<string> result;
    string current="";

    for(char c:s){
        if(c==delimiter){
            result.push_back(current);
            current="";
        }
        else{
            current+=c;
        }
    }
    result.push_back(current);
    return result;
}

int main() {
    int n;
    cout<<"Enter number of Productions: ";
    cin>>n;
    cin.ignore();

    vector<string> lhs(n);
    vector<string> rhs(n);
    cout<<"Enter Production: "<<endl;
    for(int i=0;i<n;i++){
        cin>>lhs[i]>>rhs[i];
    }

    for(int i=0;i<n;i++){
        string A=lhs[i];
        vector<string> prod=split(rhs[i],'|');

        vector<string> alpha;
        vector<string> beta;

        for(string p:prod){
            if(p.substr(0,A.size())==A){
                alpha.push_back(p.substr(A.size()));
            }
            else{
                beta.push_back(p);
            }
        }
        if(alpha.empty()){
            cout<<A<<" -> "<<rhs[i]<<endl;
            continue;
        }
        string Aprime=A+"'";
        cout<<A<<" -> ";
        for(int k=0;k<beta.size();k++){
            cout<<beta[k]<<Aprime;
            if(k!= beta.size()-1){
                cout<<" | ";
            }
        }
        cout<<endl;

        cout<<Aprime<<" -> ";
        for(int k=0;k<alpha.size();k++){
            cout<<alpha[k]<<Aprime;
            if(k!= alpha.size()-1){
                cout<<" | ";
            }
        }
        cout<<" | epsilon"<<endl;
    }
    
    return 0;
}
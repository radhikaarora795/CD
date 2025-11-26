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

string commonPrefix(string a,string b){
    string prefix="";
    int n=min(a.size(),b.size());
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            prefix+=a[i];
        }
        else{
            break;
        }
    }
    return prefix;
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

        bool factored=false;

        for(int j=0;j<prod.size();j++){
            for(int k=j+1;k<prod.size();k++){
                string prefix=commonPrefix(prod[j],prod[k]);
                if(prefix != ""){
                    string Aprime=A+"'";
                    factored=true;

                    cout<<A<<" -> "<<prefix<<Aprime<<endl;;
                    cout<<Aprime<<" -> ";
                    string rem1=prod[j].substr(prefix.size());
                    string rem2=prod[k].substr(prefix.size());

                    if(rem1 == ""){
                        rem1="epsilon";
                    }
                    if(rem2 == ""){
                        rem2="epsilon";
                    }

                    cout<<rem1<<" | "<<rem2<<endl;
                    break;
                }
            }
            if(factored){
                break;
            }
        }
        if(!factored){
        cout<<A<<" -> ";
        for(int j=0;j<prod.size();j++){
            cout<<prod[j];
            if(j != prod.size()-1){
                cout<<" | ";
            }
        }
        cout<<endl;
    }

    }
    
    return 0;
}
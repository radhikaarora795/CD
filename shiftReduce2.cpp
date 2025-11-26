#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of productions: ";
    cin>>n;
    vector<string> lhs(n),rhs(n);
    cout<<"Enter Productions: "<<endl;
    for(int i=0;i<n;i++){
        cin>>lhs[i]>>rhs[i];
    }

    string start=lhs[0];
    string input;
    cout<<"Enter input string: ";
    cin>>input;

    string stack;
    for(int i=0;i<input.size();i++){
        stack+=input[i];
        cout<<"Shift"<<endl;
        bool reduced=true;
        while(reduced){
            reduced=false;
            for(int p=0;p<n;p++){
                int L=rhs[p].size();
                int S=stack.size();
                if(S>=L && stack.substr(S-L,L) == rhs[p]){
                    stack.replace(S-L,L,lhs[p]);
                    cout<<"Reduce "<<lhs[p]<<" -> "<<rhs[p]<<endl;
                    reduced=true;
                }
            }
        }
    }
    if(stack == start){
        cout<<"Accept"<<endl;
    }
    else{
        cout<<"Reject"<<endl;
    }
    
    return 0;
}
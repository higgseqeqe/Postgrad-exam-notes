#include<iostream>
using namespace std;

bool isValid(string s) {
    if(s.size() % 2 != 0) return false;
    string stk ;
    for(int i= 0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            stk.push_back(s[i]);
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(stk.empty())
                return false;
            if(stk.back()=='('){
                if(s[i]==')'){
                    stk.pop_back();
                }else{
                    return false;
                }
            }
            else if(stk.back()=='{'){
                if(s[i]=='}'){
                    stk.pop_back();
                }else{
                    return false;
                }
            }
            else if(stk.back()=='['){
                if(s[i]==']'){
                    stk.pop_back();
                }
                else{
                    return false;
                }
            }

        }
    }
    return stk.empty();
}

int main() {
    string s= "[]{}()";
    string s1="(){";
    string s3="({)";

    cout<<isValid(s)<<endl;
    cout<<isValid(s1)<<endl;
    cout<<isValid(s3)<<endl;


}
#include<bits/stdc++.h>
using namespace std;
int checklevel(char c){
    if(c=='^')return 3;
    else if(c=='*'||c=='/')return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}
string rev(string s){
    int i,n=s.size()-1;
    string change;
    for(i=n;i>=0;i--){
        if(s[i]==')')s[i]='(';
        else if(s[i]=='(')s[i]=')';
        change+=s[i];
    }
    return change;
}
bool IsitChar(char c){

    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))return true;
    return false;
}
string toPostfix(string s){
    //s=rev(s);
    stack<char>operetor;
    int i,n=s.size();
    string output;
    operetor.push('x');
    for(i=0;i<n;i++){
        if(IsitChar(s[i]))output+=s[i];
        else if(s[i]=='(')operetor.push(s[i]);
        else if(s[i]==')'){
            while(operetor.top()!='('&&operetor.top()!='x'){
                    output+=operetor.top();
                    operetor.pop();
            }
            if(operetor.top()=='(')
               operetor.pop();
        }else{
            if(checklevel(s[i])>=checklevel(operetor.top()))operetor.push(s[i]);
            else {
                cout<<s[i]<<" "<<operetor.top()<<endl;
                while(checklevel(s[i])<=checklevel(operetor.top())&&operetor.top()!='x'){
                    //cout<<operetor.top()<<i<<endl;
                    output+=operetor.top();
                    operetor.pop();
                }
                operetor.push(s[i]);
            }
        }
    }

    while(operetor.top()!='x'){
        output+=operetor.top();
        operetor.pop();
    }

    return output;
}
int main(){
    string s;
    while(cin>>s){
      cout<<toPostfix(s)<<endl;
    }
    return 0;
}

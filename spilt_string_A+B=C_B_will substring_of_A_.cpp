#include<iostream>
using namespace std;
bool calculate_substring(string main){
string temp1,temp2;
temp1=main.substr(0,main.size()-1);
temp2=main.substr(main.size()-1,main.size());
if(temp1.find(temp2)<=temp1.size())return true;
else return false;
}

int main(){
int test;
cin>>test;
while(test--){
    string main;
    int temp;
    cin>>temp;
    cin>>main;
    if(calculate_substring(main))cout<<"Yes"<<endl;
    else cout<<"NO\n";
}
return 0;

}

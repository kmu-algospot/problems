#include <iostream>
#include <string>
using namespace std;

string solve(int idx,string &in){
    if(in[idx] != 'x'){
        string ret(1,in[idx]);
        return ret;
    }
    string s1 = solve(idx+1,in);
    string s2 = solve(idx+1+s1.length(),in);
    string s3 = solve(idx+1+s1.length()+s2.length(),in);
    string s4 = solve(idx+1+s1.length()+s2.length()+s3.length(),in);
    return "x"+s3+s4+s1+s2;
}
int main(){
    int C;
    scanf("%d",&C);
    
    while(C--){
        string in;
        cin >> in;
        printf("%s\n",solve(0,in).c_str());
    }
    return 0;
}

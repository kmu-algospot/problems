#include <iostream>
#include <string>
using namespace std;
string make(string input,string ans);
int main(){
    int cases;
    cin>> cases;
    while(cases--){
        string input;
        cin>>input;
        string ans ="";
        cout<<make(input,ans)<<"\n";
    }
}

string make(string input,string ans){
        int idx =0;
        if(input[idx] == 'x'){
            string v1,v2,v3,v4;

            v1 = make(input.substr(idx+1),ans);
            v2 = make(input.substr(idx+1+v1.length()),ans);
            v3 = make(input.substr(idx+1+v1.length()+v2.length()),ans);
            v4 = make(input.substr(idx+1+v1.length()+v2.length()+v3.length()),ans);
            ans +='x';
            ans += v3+v4+v1+v2;
            idx +=1+v1.length()+v2.length()+v3.length();
        }else{
            ans += input[idx];
            idx++;
        }
        return ans;
}

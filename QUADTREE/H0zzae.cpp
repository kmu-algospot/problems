#include <iostream>
using namespace std;

//x xwwwb (xw xwbbb ww) (x (x xwwbb bww) wwb) b

string quadTree(string inputTree,int index){
    if (inputTree[index]=='w'||inputTree[index]=='b'){
        return inputTree.substr(index,1);
    }
    index++;

    string firstString=quadTree(inputTree,index);
    index+=firstString.length();
    string secondString=quadTree(inputTree,index);
    index+=secondString.length();
    string thirdString=quadTree(inputTree,index);
    index+=thirdString.length();
    string fourthString=quadTree(inputTree,index);
    
    string ret = 'x'+thirdString+fourthString+firstString+secondString;
    return ret;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        string inputTree;
        cin>>inputTree;
        cout<<quadTree(inputTree,0)<<endl;
    }
}
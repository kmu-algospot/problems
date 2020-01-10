#include <iostream>
using namespace std;
#define FOR(var, ed) for(int var = 0 ; var<ed; var++)

bool xIsNext(string inputTree){
    if(inputTree.substr(0,1)=="x"){
        return true;
    }
    return false;
}
string quadTree(string inputTree){
    if (inputTree=="w"||inputTree=="b"){
        return inputTree;
    }
    if(inputTree.substr(0,1)=="x"){
         inputTree = inputTree.substr(1);
    }
    string firstString;
    if (xIsNext(inputTree)){
        firstString = quadTree(inputTree.substr(0,5));
        inputTree = inputTree.substr(5);
    }else {
        firstString = quadTree(inputTree.substr(0,1));
        inputTree = inputTree.substr(1);
    }
    string secondString;
    if (xIsNext(inputTree)){
        secondString = quadTree(inputTree.substr(0,5));
        inputTree = inputTree.substr(5);
    }else {
        secondString = quadTree(inputTree.substr(0,1));
        inputTree = inputTree.substr(1);
    }
    string thirdString;
    if (xIsNext(inputTree)){
        thirdString = quadTree(inputTree.substr(0,5));
        inputTree = inputTree.substr(5);
    }else {
        thirdString = quadTree(inputTree.substr(0,1));
        inputTree = inputTree.substr(1);
    }
    string fourthString;
    if (xIsNext(inputTree)){
        fourthString = quadTree(inputTree.substr(0,5));
        inputTree = inputTree.substr(5);
    }else {
        fourthString = quadTree(inputTree.substr(0,1));
        inputTree = inputTree.substr(1);
    }
    string ret = 'x'+thirdString+fourthString+firstString+secondString;
    return ret;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        string inputTree;
        cin>>inputTree;
        cout<<quadTree(inputTree)<<endl;
    }
}
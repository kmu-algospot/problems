#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int pt[101][101] = {-1,};
int check(string wildcard,string card,int wild_idx, int card_idx);
int main(){
    int cases;
    cin>> cases;
    while(cases--){
        
        string wildcard;
        cin>> wildcard;
        int compared;
        cin>> compared;
        while(compared--){
            memset(pt,-1,sizeof(pt));
            string card;
            cin>>card;
            if(check(wildcard,card,0,0)){
                cout<<card<<"\n";
            }
        }
    }
}

int check(string wildcard,string card, int wild_idx, int card_idx){
    int &ret = pt[wild_idx][card_idx];
    if(ret != -1){
        return ret;
    } 
    ret = false;
    if(wild_idx == wildcard.length() && card_idx == card.length()){
        return true;
    }
    if(wild_idx > wildcard.length() || card_idx > card.length()){
        return false;
    }
    if(wildcard[wild_idx] == '*'){
        for(int i =0; i<= wildcard.length() - wild_idx+1; i++){
            ret = (ret || check(wildcard,card,wild_idx+1,card_idx+i));
        }
    } else if(wildcard[wild_idx] == '?'){
        ret = check(wildcard,card,wild_idx+1,card_idx+1);
    } else{
        if(wildcard[wild_idx] == card[card_idx]){
            ret = check(wildcard,card,wild_idx+1,card_idx+1);
        } else{
            ret = false;
        }
    }
    return ret;
}

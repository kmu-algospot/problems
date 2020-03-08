#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
class Object{
public:
    int count = -1;
    map<char,Object> *dict;
};
int solution(vector<string> words) {
    int answer = 0;

    map<char, Object> *root = new map<char,Object>;
    for(int i = 0; i<words.size();++i){
        string str = words[i];
        map<char, Object> *node = root;
        
        for(int j = 0; j<str.size(); ++j){
            if(node->find(str[j]) != node->end()){
                (*node)[str[j]].count+=1;
            }
            else{
                Object obj;
                obj.dict = new map<char,Object>;
                obj.count = 1;
                (*node)[str[j]] = obj;
            }
            node = (*node)[str[j]].dict;
        }
    }
    
    for(int i = 0; i<words.size();++i){
        string str = words[i];
        map<char, Object> *node = root;
        int level;
        for(level = 0; level<str.size(); ++level){
            int count = (*node)[str[level]].count;
            if(count == 1){
                answer += level + 1;
                break;
            }
            if(level == str.size()-1){
                answer += level + 1;
            }
            node = (*node)[str[level]].dict;
        }
    }
    return answer;
}

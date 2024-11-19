#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool check(int i){
    if(i / 10 != 0) {
        if(check(i / 10) == 0) return 0;
    }
    if(i % 10 == 0 || i % 10 == 5){
            return 1;
    }
    return 0;
}

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i = l; i < r + 1; i++){
        if(check(i)){
            answer.push_back(i);
        }   
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    return answer;
}

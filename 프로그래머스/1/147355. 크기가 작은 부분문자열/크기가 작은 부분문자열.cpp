#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<string> v;
    
    
    for(int i = 0; i < t.size() - p.size() + 1; i++){
        string num = "";
        for(int j = 0; j < p.size(); j++){
            num += t[i + j];
        }
        v.push_back(num);
    }
    
    for(string str : v){
        if(str <= p){
            answer++;
        }
    }
    
    return answer;
}
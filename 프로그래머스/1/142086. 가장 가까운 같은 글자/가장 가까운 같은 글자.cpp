#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<int> alpList(26, -1);
    
    for(char c : s){
        if(alpList[c - 'a'] == -1)
        {
            alpList[c - 'a']= 0;
            answer.push_back(-1);
        }
        else{
            answer.push_back(alpList[c - 'a']);
            alpList[c - 'a'] = 0;
        }
        for(int& num : alpList){
            if(num != -1){
                num++;
            }
        }
    }
    
    return answer;
}
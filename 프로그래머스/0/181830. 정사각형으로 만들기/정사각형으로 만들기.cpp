#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer = arr;
    
    int state = arr.size() - arr[0].size();
    
    if(state > 0){
        for(int i{}; i < arr.size(); i++){
            for(int j{}; j < state; j++){
                answer[i].push_back(0);
            }
        }
    }
    else if(state < 0){
        answer.resize(answer[0].size());
        for(int i = arr.size(); i < answer[0].size(); i++){
            for(int j{}; j < answer[0].size(); j++){
                answer[i].push_back(0);
            }
        }
    }
    
    return answer;
}
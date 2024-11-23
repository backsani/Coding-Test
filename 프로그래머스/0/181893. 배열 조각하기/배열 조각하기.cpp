#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer = arr;
    
    for(int i = 0; i < query.size(); i++){
        if(i % 2 == 0){
            for(int j = query[i] + 1; j < answer.size(); j++){
                answer[j] = -1;
            }
            answer.erase(remove(answer.begin(), answer.end(), -1), answer.end());
        }
        else{
            for(int j = query[i] - 1; j < answer.size(); j--){
                answer[j] = -1;
            }
            answer.erase(remove(answer.begin(), answer.end(), -1), answer.end());
        }
    }
    
    return answer;
}
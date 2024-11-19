#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    for(vector<int> v : queries){
        for(int i = v[0]; i < v[1] + 1; i++){
            if(i % v[2] == 0){
                answer[i] = answer[i] + 1;
            }
        }
    }
    
    return answer;
}
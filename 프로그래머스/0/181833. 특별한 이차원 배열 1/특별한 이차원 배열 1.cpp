#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            if(i == j) {
                answer[i][j] = 1;
            }
        }
    }
    
    return answer;
}
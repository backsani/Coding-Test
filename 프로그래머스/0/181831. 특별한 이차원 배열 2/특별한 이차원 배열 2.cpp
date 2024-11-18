#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 1;
    int length = arr.size();
    
    for(int i{}; i < length; i++){
        for(int j{}; j < length; j++){
            if((arr[i][j] == arr[j][i] && i != j )|| i == j)
                continue;
            return 0;
        }
    }
    
    return answer;
}
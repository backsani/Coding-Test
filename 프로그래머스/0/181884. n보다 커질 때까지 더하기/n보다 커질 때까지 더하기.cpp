#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    
    for(int i{}; answer <= n; i++){
        answer += numbers[i];
    }
    
    return answer;
}
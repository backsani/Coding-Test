#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    
    for(int n : number){
        answer += (int)(n - '0');
    }
    
    answer %= 9;
    
    return answer;
}
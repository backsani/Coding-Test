#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 0; i < n + 1; i += 2)
    {
        answer += i;
    }
    return answer;
}
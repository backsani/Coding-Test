#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int pack = 1;
    while(pack <= n)
    {
        answer++;
        pack *= answer;
    }
    
    return answer-1;
}
#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    
    while(chicken >= 10)
    {
        int coup = chicken / 10;
        answer += coup;
        chicken = coup + (chicken % 10);
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long number = num;
    
    while(answer != 500)
    {
        if(number == 1)
            break;
        number = number % 2 == 0 ? number / 2 : number * 3 + 1;
        answer++;
    }
    
    return answer != 500 ? answer : -1;
}
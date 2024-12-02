#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int bottle = n;
    
    while(bottle / a != 0)
    {
        int rest = (bottle % a);
        bottle = (bottle / a) * b;
        answer += bottle;
        bottle += rest;
    }
    
    
    return answer;
}
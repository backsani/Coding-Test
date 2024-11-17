#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    if(a % 2 != 0 && b % 2 != 0){
        return a*a + b*b;
    }
    
    if((a % 2 != 0 && b % 2 == 0) || (b % 2 != 0 && a % 2 == 0)){
        return 2*(a+b);
    }
    
    if(a % 2 == 0 && b % 2 == 0){
        return a - b > 0 ? a - b : -(a - b);
    }
    
    return answer;
}
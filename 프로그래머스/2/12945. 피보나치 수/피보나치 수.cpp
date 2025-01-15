#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int a = 0;
    int b = 1;
    
    for(int i = 2; i <= n; i++)
    {
        int temp = (a + b) % 1234567;
        a = b;
        b = temp;
    }
    
    return b;
}
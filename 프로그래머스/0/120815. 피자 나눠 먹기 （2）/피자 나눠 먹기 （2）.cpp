#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a,b);
}

int solution(int n) {
    int answer = 0;
    
    answer = n > 6 ? lcm(n, 6) : lcm(6, n);
    
    return answer / 6;
}
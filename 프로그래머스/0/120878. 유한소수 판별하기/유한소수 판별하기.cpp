#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int solution(int a, int b) 
{
    int temp = a > b ? gcd(a,b) : gcd(b,a);
    a /= temp;
    b /= temp;
    
    while(true)
    {
        if(b % 2 == 0)
        {
            b /= 2;
            continue;
        }
        else if(b % 5 == 0)
        {
            b /= 5;
            continue;
        }
        break;
    }
    
    if(b == 1)
        return 1;
    
    return 2;
}
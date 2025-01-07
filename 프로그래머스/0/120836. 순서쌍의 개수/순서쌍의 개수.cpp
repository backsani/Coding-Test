#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int i = 1;
    int j = n;
    while(i <= j)
    {
        if(n % i == 0)
        {
            j = n / i;
            if(i > j)
                continue;
            else if(i == j)
                answer++;
            else
                answer += 2;
        }
        i++;
    }
    
    return answer;
}
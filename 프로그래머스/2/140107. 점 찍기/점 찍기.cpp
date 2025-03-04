#include <string>
#include <vector>

using namespace std;

bool distanceCheck(pair<long long, long long> pos, long long d)
{
    if(pos.first * pos.first + pos.second * pos.second > d * d)
        return false;
    return true;
}

long long solution(int k, int d) {
    long long answer = 0;
    
    long long temp = (d / k);
    long long i = temp * k;
    
    for(long long j = 0; j <= d; j += k)
    {
        while(!distanceCheck(make_pair(i, j), d))
            i -= k;
        answer += i / k + 1;
    }
    
    return answer;
}
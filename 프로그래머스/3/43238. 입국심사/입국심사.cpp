#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long maxT = (long long)times.back() * n;
    long long minT = 1;
    answer = maxT;
    
    while(minT <= maxT)
    {
        long long midT = (maxT + minT) / 2;
        long long t = 0;
        
        for(int i : times)
        {
            t += midT / i;
            if(t >= n)
                break;
        }
        
        if(t >= n)
        {
            answer = midT;
            maxT = midT - 1;
        }
        else
        {
            minT = midT + 1;
        }
    }
    
    return answer;
}
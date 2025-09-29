#include <string>
#include <vector>
#include <bitset>

using namespace std;

long long compareBit(long long x)
{
    return x + 1 + ((x ^ (x + 1)) >> 2);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long l : numbers)
    {
        answer.push_back(compareBit(l));
    }
    
    return answer;
}
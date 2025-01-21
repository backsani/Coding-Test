#include <string>
#include <vector>

using namespace std;

int checkPosValue(long long n, long long pos)
{
    long long line = (pos / n) + 1;
    if(pos % n + 1 <= line)
        return line;
    else
    {
        return pos % n + 1;
    }
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i < right + 1; i++)
    {
        answer.push_back(checkPosValue(n, i));
    }
    
    return answer;
}
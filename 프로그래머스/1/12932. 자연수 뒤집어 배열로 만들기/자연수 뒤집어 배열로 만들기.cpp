#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n > 0)
    {
        answer.push_back((int)(n % 10));
        n = n / 10;
    }
    
    return answer;
}
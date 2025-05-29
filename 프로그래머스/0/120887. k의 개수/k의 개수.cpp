#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char target = k + '0';
    
    for(int n = i; n < j + 1; n++)
    {
        string str = to_string(n);
        answer += count(str.begin(), str.end(), target);
    }
    
    return answer;
}
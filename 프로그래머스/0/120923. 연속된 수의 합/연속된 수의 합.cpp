#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int center = ceil((double)total / num);
    int start = center - num / 2;
    
    for(int i = 0; i < num; i++)
    {
        answer.push_back(start + i);
    }
    
    return answer;
}
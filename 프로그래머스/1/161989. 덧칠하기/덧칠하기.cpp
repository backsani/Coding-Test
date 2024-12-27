#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    while(!section.empty())
    {
        int start = section[0];
        for(int i = start; i < start + m; i++)
        {
            auto it = find(section.begin(), section.end(), i);
            if (it != section.end()) {
                section.erase(it);
            }
        }
        answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    
    int count = 0;
    int min = k;
    
    for(int i = score.size() - 1; i >= 0; i--)
    {
        min = min < score[i] ? min : score[i];
        
        ++count;
        
        if(count == m)
        {
            answer += min * m;
            count = 0;
        }
    }
    
    return answer;
}
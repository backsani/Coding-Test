#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s)
        return {-1};
    
    vector<int> answer(n, 0);
    
    int result = ceil(static_cast<double>(s) / n);
    int temp = result * n - s;
    
    for(int i = 0; i < answer.size(); i++)
    {
        answer[i] = result;
        if(temp > 0)
        {
            answer[i]--;
            temp--;
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int& i : lost)
    {
        auto it = find(reserve.begin(), reserve.end(), i);
        if(it != reserve.end())
        {
            reserve.erase(it);
            i = 0;
        }
    }
    
    for(int& i : lost)
    {        
        auto it = find(reserve.begin(), reserve.end(), i - 1);
        if(it == reserve.end())
        {
            it = find(reserve.begin(), reserve.end(), i + 1);
            
            if(it == reserve.end())
            {
                continue;
            }
        }
        
        reserve.erase(it);
        i = 0;
    }
    
    for(int i : lost)
    {
        if(i != 0)
            answer--;
    }
    
    return answer;
}
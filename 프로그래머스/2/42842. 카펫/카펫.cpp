#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<vector<int>> v;
    
    int sum = brown + yellow;
    
    for(int i = 1; i * i <= sum; i++)
    {
        if(i*i % sum == 0)
        {
            v.push_back({i,i});
        }
        else if((sum / i) * i == sum)
        {
            v.push_back({sum / i , i});
            
        }
    }
    
    for(vector<int> vv : v)
    {
        if((vv[0] - 2) * (vv[1] - 2) == yellow)
            answer = {vv[0], vv[1]};
    }


    return answer;
}
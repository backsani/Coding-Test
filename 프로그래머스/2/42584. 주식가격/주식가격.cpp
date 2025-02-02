#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> s;
    
    for(int i = prices.size() - 1; i >= 0; i--)
    {
        int j = 1;
        if(i + j > prices.size() - 1)
        {
            s.push(0);
            continue;
        }
            
        while(i + j < prices.size() - 1 && prices[i + j] >= prices[i])
        {
            j++;
        }
        s.push(j);
    }
    
    while(!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }
    
    return answer;
}
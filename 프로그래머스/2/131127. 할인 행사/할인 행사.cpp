#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    queue<string> q;
    
    for(int i = 0; i < want.size(); i++)
    {
        m[want[i]] = number[i];
    }
    
    for(int i = 0; i < discount.size(); i++)
    {
        if(q.size() < 10)
        {
            q.push(discount[i]);
            if(m.find(discount[i]) != m.end())
            {
                m[discount[i]]--;
            }
        }
        else
        {
            string s = q.front();
            q.pop();
            
            if(m.find(s) != m.end())
            {
                m[s]++;
            }
            
            q.push(discount[i]);
            if(m.find(discount[i]) != m.end())
            {
                m[discount[i]]--;
            }
        }
        
        bool end = true;
        
        for(pair<string, int> num : m)
        {
            if(num.second != 0)
            {
                end = false;
                break;
            }
                
        }
        
        if(end)
            answer++;
    }
    
    return answer;
}
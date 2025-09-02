#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<string> BFS(vector<vector<string>>& t)
{
    vector<string> answer;
    
    sort(t.begin(), t.end(), [](const vector<string>& a, const vector<string>& b){
        return a[1] < b[1];
    });
    
    map<string, int> m;
    
    int index = 1;
    for(vector<string> ticket : t)
    {
        if(m[ticket[0]] == 0)
            m[ticket[0]] = index++;
        if(m[ticket[1]] == 0)
            m[ticket[1]] = index++;
    }
    
    vector<vector<string>> des(m.size() + 1, vector<string>());
    for(vector<string> v : t)
    {
        des[m[v[0]]].push_back(v[1]);
    }
    
    // {{ 남은 경로, 진행한 경로}, 다음 목적지}
    queue<pair<pair<vector<vector<string>>, vector<string>>, string>> q;
    vector<vector<string>> temp = des;
    q.push({ { des, vector<string>() }, "ICN"});
    
    while(!q.empty())
    {
        pair<pair<vector<vector<string>>, vector<string>>, string> p = q.front();
        q.pop();
        
        vector<vector<string>> les = p.first.first;
        vector<string> answer = p.first.second;
        string prev = p.second;
        
        answer.push_back(prev);
        
        vector<vector<string>> lesQ = les;
        for(int i = 0; i < lesQ[m[prev]].size(); i++)
        {
            string next = lesQ[m[prev]][i];
            vector<vector<string>> nextQ = lesQ;
            nextQ[m[prev]].erase(nextQ[m[prev]].begin() + i);
            
            if(answer.size() == t.size())
            {
                answer.push_back(next);
                return answer;
            }
            
            q.push({{nextQ, answer}, next});
        }
    }
    
    return {};
}

vector<string> solution(vector<vector<string>> tickets) {
    return BFS(tickets);
}
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int bfs(map<int, queue<int>>& m)
{
    queue<pair<int, int>> q;
    set<int> visited;
    
    q.push({1, 0});
    visited.insert(1);
    map<int, int> count;
        
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        while(!m[current.first].empty())
        {
            int size = visited.size();
            
            int next = m[current.first].front();
            m[current.first].pop();
            
            visited.insert(next);
            if(visited.size() == size)
                continue;
            
            q.push({next, current.second + 1});
            count[current.second + 1]++;
        }
    }
    
    return count[count.size()];
}

int solution(int n, vector<vector<int>> edge) {
    map<int, queue<int>> m;
    
    for(vector<int> v : edge)
    {
        m[v[0]].push(v[1]);
        m[v[1]].push(v[0]);
    }

    return bfs(m);;
}
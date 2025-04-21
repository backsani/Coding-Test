#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int bfs(vector<vector<int>>& v)
{
    queue<pair<int, int>> q;
    set<int> visited;
    int step = 0;
    int index = 0;
    
    q.push({1, 0});
    visited.insert(1);
    map<int, int> count;
    
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        for(int i : v[current.first])
        {
            int size = visited.size();
            visited.insert(i);
            
            if(size == visited.size())
                continue;
            
            q.push({i, current.second + 1});
            count[current.second + 1]++;
        }
    }
    
    return count[count.size()];
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> v(n + 1, vector<int>());
    for(vector<int> temp : edge)
    {
        v[temp[0]].push_back(temp[1]);
        v[temp[1]].push_back(temp[0]);
    }
    
    return bfs(v);
}
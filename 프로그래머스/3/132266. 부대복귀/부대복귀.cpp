#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& road, int destination)
{
    // int : start, int : step
    queue<pair<int, int>> q;
    set<int> s;
    
    q.push({destination, 0});
    s.insert(destination);
    
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        road[current.first][0] = current.second;
        
        for(int i = 0; i < road[current.first].size(); i++)
        {
            if(road[current.first][i] == -1 || i == 0)
                continue;
            if(s.find(road[current.first][i]) != s.end())
                continue;
            
            s.insert(road[current.first][i]);
            q.push({road[current.first][i], current.second + 1});
        }
    }
    
    
    return;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> road(n + 1, vector<int>(1, -1));
    
    for(vector<int> v : roads)
    {
        road[v[0]].push_back(v[1]);
        road[v[1]].push_back(v[0]);
    }
    
    bfs(road, destination);
    
    for(int i : sources)
    {
        answer.push_back(road[i][0]);
    }
    
    return answer;
}
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs(vector<vector<int>>& maps)
{
    vector<pair<int, int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    pair<int, int> currentPos = {0,0};
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    queue<pair<pair<int,int>, int>> q;
    
    q.push({currentPos, 1});
    visited[0][0] = true;
    
    while(!q.empty())
    {
        pair<pair<int, int>, int> currentNode = q.front();
        q.pop();
        
        pair<int, int> pos = currentNode.first;
        int step = currentNode.second;
        
        for(size_t i = 0; i < direction.size(); i++)
        {
            int ny = direction[i].first + pos.first;
            int nx = direction[i].second + pos.second;
            
            if(ny >= maps.size() || ny < 0 || nx >= maps[0].size() || nx < 0 || maps[ny][nx] == 0 || visited[ny][nx] == true)
                continue;
            
            if(ny == maps.size() - 1 && nx == maps[0].size() -1)
                return step + 1;
            
            q.push({{ny, nx}, step + 1});
            visited[ny][nx] = true;
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return bfs(maps);;
}
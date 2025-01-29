#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    visited[0][0] = true;
    
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    q.push(make_pair(make_pair(0,0), 1));
    
    while(!q.empty())
    {
        pair<pair<int, int>, int> currentPos = q.front();
        q.pop();
        
        int x = currentPos.first.first;
        int y = currentPos.first.second;
        
        int steps = currentPos.second;
        
        if(x == maps[0].size() - 1 && y == maps.size() - 1)
            return steps;
        
        for(pair<int, int> p : direction)
        {
            int nextX = x + p.first;
            int nextY = y + p.second;
            
            if(nextX >= 0 && nextX < maps[0].size() && nextY >= 0 && nextY < maps.size() && visited[nextY][nextX] != true && maps[nextY][nextX] != 0)
            {
                visited[nextY][nextX] = true;
                q.push(make_pair(make_pair(nextX, nextY), steps + 1));
            }
        }
    }
    
    return -1;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> map;

int FindIsland(vector<vector<bool>>& visited, pair<int, int> Pos)
{
    int result = 0;
    queue<pair<int, int>> q;
    
    vector<pair<int, int>> direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    q.push(Pos);
    
    while(!q.empty())
    {
        Pos = q.front();
        q.pop();
        
        if(map[Pos.first][Pos.second] != 'X' && visited[Pos.first][Pos.second] == false)
        {
            result += map[Pos.first][Pos.second] - '0';
            visited[Pos.first][Pos.second] = true;
        }
        else
            continue;
            
        
        for(int i = 0; i < 4; i++)
        {
            //y, x 순으로 저장
            pair<int, int> nextPos = {Pos.first + direction[i].first, Pos.second + direction[i].second};
            if(nextPos.first >= 0 && nextPos.first < map.size() && nextPos.second >= 0 && nextPos.second < map[0].length() && visited[nextPos.first][nextPos.second] == false)
            {
                if(map[nextPos.first][nextPos.second] == 'X')
                    continue;

                q.push(nextPos);
            }
        }
    }
    
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    map = maps;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j< maps[0].size(); j++)
        {
            if(visited[i][j])
                continue;
            int temp = FindIsland(visited, {i, j});
            if(temp != 0)
                answer.push_back(temp);
        }
    }
    
    if(answer.empty())
        return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
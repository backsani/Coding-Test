#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<vector<char>> maps;

int bfs(pair<int, int> pos)
{
    vector<vector<int>> direction = { {0,1}, {1,0}, {0, -1}, {-1, 0} };
    
    //방문했던 좌표(출발좌표, 도착좌표)
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    //현재 좌표, 이동 횟수
    queue<pair<pair<int, int>, int>> q;
    
    q.push(make_pair(pos, 0));
    
    while(!q.empty())
    {
        pair<int, int> currentPos = q.front().first;
        int step = q.front().second;
        q.pop();
        
        for(int k = 0; k < 4; k++)
        {
            int ny = currentPos.first + direction[k][0];
            int nx = currentPos.second + direction[k][1];
            
            if(ny >= maps.size() || ny < 0 || nx >= maps[0].size() || nx < 0 || maps[ny][nx] == 'D')
            {
                continue;
            }
            while(true)
            {
                ny += direction[k][0];
                nx += direction[k][1];
                
                if(ny >= maps.size() || ny < 0 || nx >= maps[0].size() || nx < 0 || maps[ny][nx] == 'D')
                {
                    ny -= direction[k][0];
                    nx -= direction[k][1];
                    
                    if(maps[ny][nx] == 'G')
                    {
                        return step + 1;
                    }
                    
                    int count = visited.size();
                    visited.insert(make_pair(currentPos, make_pair(ny, nx)));
                    
                    if(count == visited.size())
                        break;
                    
                    q.push(make_pair(make_pair(ny, nx), step + 1));
                    break;
                }
                
                
            }
        }
    }
        
    return -1;
}

int solution(vector<string> board) {
    maps.assign(board.size(), vector<char>(board[0].size()));
    pair<int, int> Pos;
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            maps[i][j] = board[i][j];
            if(board[i][j] == 'R')
                Pos = make_pair(i, j);
        }
    }
    
    return bfs(Pos);
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y,x});
    
    visited[y][x] = true;
    
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        visited[current.first][current.second] = true;
        
        for(int i = -1; i < 2; i++)
        {
            for(int j = -1; j < 2; j++)
            {
                int ny = current.first + i;
                int nx = current.second + j;
                if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size() || visited[ny][nx])
                    continue;
                
                if(board[ny][nx] == 1)
                {
                    q.push({ny, nx});
                    continue;
                }
                    
                board[ny][nx] = -1;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 1)
                bfs(board, visited, i, j);
        }
    }
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 0)
                answer++;
        }
    }
    
    return answer;
}
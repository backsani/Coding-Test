#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

enum state{
    Right = 0,
    Down = 1,
    Left = 2,
    Up = 3
    
};

vector<vector<int>> solution(int n) {
    int direction = state::Right;
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    
    int x = 0;
    int y = 0;
    
    for(int num = 1; num < (n * n) + 1; num++){
        answer[y][x] = num;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(nx >= n || nx < 0 || ny >= n || ny < 0 || answer[ny][nx] != 0){
            direction = (++direction) % 4;
        }
        
        x += dx[direction];
        y += dy[direction];
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> skillCompression(n + 1, vector<int>(m + 1, 0));
    
    for(vector<int>& v : skill)
    {
        int value = v[0] == 1 ? v[5] * -1 : v[5];
        
        skillCompression[v[1]][v[2]] += value;
        skillCompression[v[1]][v[4] + 1] -= value;
        skillCompression[v[3] + 1][v[2]] -= value;
        skillCompression[v[3] + 1][v[4] + 1] += value;
    }
    
    for (int i = 0; i < n + 1; ++i) 
    {
        for (int j = 1; j < m + 1; ++j) 
        {
            skillCompression[i][j] += skillCompression[i][j - 1];
        }
    }
    
    for (int j = 0; j < m + 1; ++j) 
    {
        for (int i = 1; i < n + 1; ++i) 
        {
            skillCompression[i][j] += skillCompression[i - 1][j];
        }
    }
    
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (board[i][j] + skillCompression[i][j] > 0)
                ++answer;
        }
    }
    
    return answer;
}
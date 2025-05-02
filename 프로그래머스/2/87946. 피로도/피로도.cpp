#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int dfs(int k, vector<vector<int>>& dungeons, vector<bool> visited, int clear)
{
    int result = clear;
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visited[i] || dungeons[i][0] > k)
            continue;
        
        visited[i] = true;
        result = max(dfs(k - dungeons[i][1], dungeons, visited, clear + 1), result);
        visited[i] = false;
    }
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    return dfs(k, dungeons, visited, 0);
}
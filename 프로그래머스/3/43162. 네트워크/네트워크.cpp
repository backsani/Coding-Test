#include <string>
#include <vector>

using namespace std;

void dfs(vector<bool>& visited, vector<vector<int>> computer, int j)
{
    visited[j + 1] = true;
    for(int i = 0; i < computer[j].size(); i++)
    {
        if(i == j || visited[i + 1] == true || computer[j][i] == 0)
            continue;
        
        dfs(visited, computer, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n + 1, false);
    vector<int> network;
    
    for(int i = 0; i < computers.size(); i++)
    {
        if(visited[i + 1] == true)
            continue;
        
        for(int j = 0; j < computers[0].size(); j++)
        {
            if(i == j || computers[i][j] == 0)
                continue;
            
            dfs(visited, computers, j);
        }
        
        network.push_back(i + 1);
    }
    
    return network.size();
}
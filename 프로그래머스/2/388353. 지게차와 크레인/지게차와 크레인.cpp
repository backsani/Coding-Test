#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int crane(vector<vector<char>>& storage, string target)
{
    int targetCount = 0;
    
    for(int i = 0; i < storage.size(); i++)
    {
        for(int j = 0; j < storage[0].size(); j++)
        {
            if(storage[i][j] == target[0])
            {
                targetCount++;
                storage[i][j] = ' ';
            }
        }
    }
    
    return targetCount;
}

int lift(vector<vector<char>>& storage, char target)
{
    int targetCount = 0;
    
    vector<vector<bool>> visit(storage.size(), vector<bool>(storage[0].size(), false));
    queue<pair<int, int>> q;
    
    pair<int, int> sideDirection[4] = { {0, 1}, {1, 0}, {0 , -1}, {-1, 0} };
    
    // 현재 y,x 좌표
    pair<int, int> currentPos = { 0, 0 };
    
    for(int i = 0; i < 4; i++)
    {
        while(true)
        {
            int ny = currentPos.first + sideDirection[i].first;
            int nx = currentPos.second + sideDirection[i].second;
            
            if(nx < 0 || nx >= storage[0].size() || ny < 0 || ny >= storage.size() || visit[ny][nx])
                break;
            if(storage[ny][nx] == ' ')
            {
                q.push({ny, nx});
            }
            
            if(storage[ny][nx] == target)
            {
                targetCount++;
                storage[ny][nx] = ' ';
            }
            
            currentPos.first = ny;
            currentPos.second = nx;
            
            visit[ny][nx] = true;
        }
    }
    
    pair<int, int> direction[4] = { {0, 1}, {1, 0}, {0 , -1}, {-1, 0} };
    
    while(!q.empty())
    {
        pair<int, int> currentPos = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = currentPos.first + direction[i].first;
            int nx = currentPos.second + direction[i].second;
            
            if(nx < 0 || nx >= storage[0].size() || ny < 0 || ny >= storage.size() || visit[ny][nx])
                continue;
            if(storage[ny][nx] == ' ')
            {
                visit[ny][nx] = true;
                q.push({ny, nx});
                continue;
            }
            
            if(storage[ny][nx] == target)
            {
                targetCount++;
                storage[ny][nx] = ' ';
                
            }
            
            visit[ny][nx] = true;
        }
    }
    return targetCount;
}

int solution(vector<string> storage, vector<string> requests) 
{
    int answer = 0;
    
    vector<vector<char>> storageV;
    
    for(int i = 0; i < storage.size(); i++)
    {
        vector<char> temp;
        for(int j = 0; j < storage[i].size(); j++)
        {
            temp.push_back(storage[i][j]);
        }
        storageV.push_back(temp);
    }
    int storageSize = storage.size() * storage[0].size();
    
    for(string str : requests)
    {
        if(str.size() == 1)
        {
            answer += lift(storageV, str[0]);
        }
        else
        {
            answer += crane(storageV, str);
        }
    }
    
    return storageSize - answer;
}
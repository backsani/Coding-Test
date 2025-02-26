#include <string>
#include <vector>

#define OUT

using namespace std;

bool checkSit(vector<string> room, int x, int y, int prevx, int prevy)
{
    if(prevx == x && prevy == y)
        return true;
    
    if(x < 0 || y < 0 || x >= room[0].size() || y >= room.size())
        return true;
    
    if(room[y][x] == 'P')
        return false;
    return true;
}

bool researchSit(vector<string> room, int x, int y)
{
    vector<pair<int, int>> direction = {  {0,1}, {1,0}, {0,-1}, {-1,0}};
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + direction[i].first;
        int ny = y + direction[i].second;
        
        if(nx < 0 || ny < 0 || nx >= room[0].size() || ny >= room.size())
            continue;
        
        if(room[ny][nx] == 'P')
            return false;
        else if(room[ny][nx] == 'X')
            continue;
        else
        {
            for(int j = 0; j < 4; j++)
            {
                if(!checkSit(room, nx + direction[j].first, ny + direction[j].second, x, y))
                    return false;
            }
            
        }
        
    }
    
    return true;
}

bool checkRoom(vector<string> room)
{
    for(int i = 0; i < room.size(); i++)
    {
        for(int j = 0; j < room[0].size(); j++)
        {
            if(room[i][j] != 'P')
                continue;
            
            if(!researchSit(room, j, i))
            {
                return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> v : places)
    {
        if(!checkRoom(v))
        {
            answer.push_back(0);
            continue;
        }
            
        answer.push_back(1);
    }
    
    return answer;
}
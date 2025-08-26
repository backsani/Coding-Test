#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> dfs(vector<vector<int>>& arr)
{
    int size = arr[0].size();
    int haf = size / 2;
    vector<pair<int, int>> area = { {0, 0}, {0, size / 2}, {size / 2, 0}, {size / 2, size / 2}};
    
    map<int, int> result;
    
    if(haf == 1)
    {
        result[arr[0][0]]++;
        result[arr[0][1]]++;
        result[arr[1][0]]++;
        result[arr[1][1]]++;
        
        return result;
    }
    
    for(int i = 0; i < 4; i++)
    {
        pair<int, int> range = area[i];
        
        vector<vector<int>> v(haf, vector<int>(haf, 0));
        map<int, int> count;
        
        for(int j = 0; j < haf; j++)
        {
            for(int k = 0; k < haf; k++)
            {
                int nx = k + range.second;
                int ny = j + range.first;
                
                v[j][k] = arr[ny][nx];
                count[arr[ny][nx]]++;
            }
        }
        
        if(count[0] == (haf * haf) || count[1] == (haf * haf))
        {
            count[0] = count[0] / (haf * haf);
            count[1] = count[1] / (haf * haf);
        }
        else
        {
            count = dfs(v);
        }
        
        result[0] += count[0];
        result[1] += count[1];
    }
    
    return result;
}

vector<int> solution(vector<vector<int>> arr) {
    map<int, int> m;
    m = dfs(arr);

    if(m[0] == 0)
        return {0,1};
    else if(m[1] == 0)
        return {1,0};
    
    return {m[0], m[1]};
}
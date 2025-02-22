#include <string>
#include <vector>
#include <climits>

using namespace std;


int turn(vector<vector<int>>& map, vector<int> v)
{
    int k = 0;
    vector<pair<int, int>> direction = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int minValue = INT_MAX;

    int i = v[0] - 1;
    int j = v[1] - 1;
    
    int prev = map[i][j];
    
    while(k < 4)
    {
        int ny = i + direction[k].first;
        int nx = j + direction[k].second;
        
        if(ny >= v[2] || nx >= v[3] || ny < v[0] - 1 || nx < v[1] - 1)
        {
            k++;
            continue;
        }
        else
        {
            minValue = min(minValue, prev);
            int temp = map[ny][nx];
            map[ny][nx] = prev;
            prev = temp;
        }
        
        i = ny;
        j = nx;
    }
    
    return minValue;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> map(rows, vector<int>(columns, 0));

    int num = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            map[i][j] = num;
            num++;
        }
    }
    
    for(vector<int> v : queries)
    {
        answer.push_back(turn(map, v));
    }
    
    return answer;
}
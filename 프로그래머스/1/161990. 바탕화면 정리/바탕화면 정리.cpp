#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int minY = numeric_limits<int>::max();
    int maxY = numeric_limits<int>::min();
    int minX = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0 ; j < wallpaper[0].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                minY = minY > i ? i : minY;
                maxY = maxY < i ? i : maxY;
                minX = minX > j ? j : minX;
                maxX = maxX < j ? j : maxX;
            }
        }
    }
    return {minY, minX, maxY + 1, maxX + 1};
}
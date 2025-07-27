#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    vector<int> dot = dots[0];
    int height = 0;
    int width = 0;
    
    for(vector<int> v : dots)
    {
        if(dot[0] != v[0] && dot[1] == v[1])
        {
            width = v[0] - dot[0];
        }
        if(dot[1] != v[1] && dot[0] == v[0])
        {
            height = v[1] - dot[1];
        }
    }
    
    return abs(width) * abs(height);
}
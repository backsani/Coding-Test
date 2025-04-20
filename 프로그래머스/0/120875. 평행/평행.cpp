#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    for(int i = 0; i < dots.size(); i++)
    {
        for(int j = i + 1; j < dots.size(); j++)
        {
            vector<vector<int>> temp;
            
            for(int k = 0; k < dots.size(); k++)
            {
                if(k == i || k == j)
                    continue;
                temp.push_back(dots[k]);
            }
            
            int aSlope = (dots[j][1] - dots[i][1]) * (temp[1][0] - temp[0][0]);
            int bSlope = (temp[1][1] - temp[0][1]) * (dots[j][0] - dots[i][0]);
            
            if (aSlope == bSlope)
                return 1;
        }
    }
    
    return answer;
}
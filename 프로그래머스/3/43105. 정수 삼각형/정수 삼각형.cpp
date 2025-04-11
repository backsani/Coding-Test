#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            int leftSum;
            int rightSum;
            
            if(j - 1 < 0)
            {
                leftSum = 0;
                rightSum = triangle[i - 1][j] + triangle[i][j];
            }
            else if(j == triangle[i - 1].size())
            {
                leftSum = triangle[i - 1][j - 1] + triangle[i][j];
                rightSum = 0;
            }
            else
            {
                leftSum = triangle[i - 1][j - 1] + triangle[i][j];
                rightSum = triangle[i - 1][j] + triangle[i][j];
            }
            
            triangle[i][j] = max(leftSum, rightSum);
        }
    }
    
    return *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}
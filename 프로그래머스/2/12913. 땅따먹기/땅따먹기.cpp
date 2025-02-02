#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<int> prev(4,0);
    prev = land[0];
    
    
    for(int i = 1; i < land.size(); i++)
    {
        vector<int> current = land[i];
        for(int j = 0; j < land[0].size(); j++)
        {
            int max = 0;
            for(int k = 0; k < land[0].size(); k++)
            {
                if(j != k)
                {
                    max = max > prev[k] + current[j] ? max : prev[k] + current[j];
                }
            }
            current[j] = max;
        }
        prev = current;
    }
    

    return *max_element(prev.begin(), prev.end());
}
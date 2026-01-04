#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int level = *max_element(diffs.begin(), diffs.end());
    int minLevel = 0;
    int maxLevel = level;
    
    while(minLevel != maxLevel)
    {
        long long currentTime = 0;
        int prevTime = 0;
        bool stop = false;
        
        for(int j = 0; j < diffs.size(); j++)
        {
            int currentDiffs = times[j];
            
            if(diffs[j] > level)
            {
                int distance = diffs[j] - level;
                distance = distance < 0 ? distance * - 1 : distance;
                currentTime += ((prevTime + currentDiffs) * distance) + currentDiffs;
                prevTime = currentDiffs;
            }
            else
            {
                currentTime += currentDiffs;
                prevTime = currentDiffs;
            }
            
            if(limit < currentTime)
            {
                stop = true;
                break;
            }
        }
        
        if(stop)
        {
            minLevel = level;
            level = level + ceil((float)(maxLevel - level) / 2);
            continue;
        }
        
        maxLevel = level;
        level = ceil((float)(level + minLevel) / 2);
        
        if(maxLevel == level)
            break;
    }
    
    return maxLevel;
}
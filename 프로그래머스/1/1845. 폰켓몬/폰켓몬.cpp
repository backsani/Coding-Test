#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int num = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    
    int prev = 0;
    for(int poketmon : nums)
    {
        if(prev != poketmon)
        {
            answer++;
            prev = poketmon;
            if(--num <= 0)
                break;
        }
    }
    
    return answer;
}
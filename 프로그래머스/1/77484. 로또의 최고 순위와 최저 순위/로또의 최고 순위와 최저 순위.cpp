#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2,7);
    
    
    for(int i : lottos)
    {
        if(i == 0)
        {
            answer[0]--;
        }
    }
    
    for(int number : win_nums)
    {
        if(find(lottos.begin(), lottos.end(), number) != lottos.end())
        {
            answer[0]--, answer[1]--;
        }
    }
    
    for(int& i : answer)
    {
        if(i == 7)
            i = 6;
    }
    
    return answer;
}
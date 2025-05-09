#include <string>
#include <vector>

using namespace std;

int changeMin(int i)
{
    int hour = i / 100;
    int minute = i % 100;
    
    return hour * 60 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int& i : schedules)
    {
        i = changeMin(i) + 10;
    }
    for(vector<int>& v : timelogs)
    {
        for(int& i : v)
        {
            i = changeMin(i);
        }
    }
    
    for(int i = 0; i < schedules.size(); i++)
    {
        bool event = true;
        int day = startday;
        for(int j = 0; j < timelogs[0].size(); j++)
        {
            if(day < 6)
            {
                if(schedules[i] < timelogs[i][j])
                {
                    event = false;
                    break;
                }
            }
                
            day = (day) % 7 + 1;
        }
        if(event)
            answer++;
    }
    
    return answer;
}
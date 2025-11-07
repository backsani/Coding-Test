#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timeToMinute(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string minuteToTime(int time)
{
    string answer = "";
    if(time/60 < 10)
        answer = "0" + to_string(time/60);
    else
        answer = to_string(time/60);
    
    if(time % 60 < 10)
        answer = answer + ":" + "0" + to_string(time%60);
    else
        answer = answer + ":" + to_string(time%60);
    
    return answer;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int currentTime = 540; // 9시부터 운행 시작
    vector<int> minuteTable;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(string str : timetable)
    {
        pq.push(timeToMinute(str));
    }
    
    int passenger = 0;
    int prevCrew = 0;
    for(int i = 0; i < n; i++)
    {
        passenger = 0;
        
        while(!pq.empty() && passenger < m && pq.top() <= currentTime)
        {
            passenger++;
            prevCrew = pq.top();
            pq.pop();
        }
        if(pq.empty())
            break;
        
        if(i + 1 < n)
            currentTime += t;
    }
    
    if(passenger < m)
        return minuteToTime(currentTime);
    else
        return minuteToTime(prevCrew - 1);
    
    return "err";
}
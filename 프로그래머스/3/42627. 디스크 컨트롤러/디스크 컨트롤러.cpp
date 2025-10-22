#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0])
        {
            if(a[1] == b[1])
            {
                return a[2] > b[2];
            }
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // 소요시간, 요청시각, 작업번호 순으로 저장
    vector<vector<int>> sortJobs;
    
    int i = 0;
    for(vector<int> job : jobs)
    {
        sortJobs.push_back({job[1], job[0], i++});
    }
    
    sort(sortJobs.begin(), sortJobs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    
    priority_queue<vector<int>, vector<vector<int>>, Compare> q;
    
    vector<int> disk = {};
    int currentTime = 0;
    int index = 0;
    int done = 0;
    
    while(done < jobs.size())
    {
        while(index < jobs.size() && currentTime >= sortJobs[index][1])
        {
            q.push({sortJobs[index][0], sortJobs[index][1], index});
            index++;
        }
        
        if(q.empty())
        {
            currentTime = sortJobs[index][1];
            continue;
        }
        
        disk = q.top();
        q.pop();
        currentTime += disk[0];
        answer += currentTime - disk[1];
        done++;
    }
    
    return answer / jobs.size();
}
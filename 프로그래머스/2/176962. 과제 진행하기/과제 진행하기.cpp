#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    stack<pair<string, int>> stopStack;
    
    for(vector<string>& plan : plans)
    {
        string start = to_string(stoi(plan[1].substr(0,2)) * 60 + stoi(plan[1].substr(3,2)));
        plan[1] = start;
    }
    
    sort(plans.begin(), plans.end(), [](vector<string> v1, vector<string> v2){
        return stoi(v1[1]) < stoi(v2[1]);
    });
    
    int remain = 0;
    
    for(int i = 0; i < plans.size(); i++)
    {
        if(i == plans.size() - 1)
        {
            answer.push_back(plans[i][0]);
            break;
        }
        
        string current = plans[i][0];
        int start = stoi(plans[i][1]);
        int time = stoi(plans[i][2]);
        
        int next = stoi(plans[i+1][1]);
        
        if(start + time <= next)
        {
            answer.push_back(current);
            
            remain = next - (start + time);
            while(remain > 0 && !stopStack.empty())
            {
                pair<string, int> subject = stopStack.top();
                stopStack.pop();
                
                if(subject.second <= remain)
                {
                    remain -= subject.second;
                    answer.push_back(subject.first);
                }
                else
                {
                    subject.second -= remain;
                    remain = 0;
                    stopStack.push(subject);
                }
            }
        }
        else
        {
            stopStack.push(make_pair(current, (start + time) - next));
        }
    }
    
    while(!stopStack.empty())
    {
        answer.push_back(stopStack.top().first);
        stopStack.pop();
    }
    
    return answer;
}
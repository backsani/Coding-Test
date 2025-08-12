#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>

using namespace std;

void cleanMax(priority_queue<int>& queue, unordered_map<int, int>& m)
{
    while(!queue.empty() && m[queue.top()] == 0)
    {
        queue.pop();
    }
    return;
}

void cleanMin(priority_queue<int, vector<int>, greater<int>>& queue, unordered_map<int, int>& m)
{
    while(!queue.empty() && m[queue.top()] == 0)
    {
        queue.pop();
    }
    return;
}

vector<int> solution(vector<string> operations) {
    unordered_map<int, int> m;
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    
    for(const string& str : operations)
    {
        stringstream ss(str);
        
        string s;
        string i;
        ss >> s >> i;
        int num = stoi(i);
        
        if(s == "I")
        {
            m[num]++;
            maxQ.push(num);
            minQ.push(num);
        }
        else
        {            
            int temp;
            
            if(maxQ.empty() || minQ.empty())
                continue;
            
            if(num == 1)
            {
                cleanMax(maxQ, m);
                if(maxQ.empty())
                    continue;
                
                temp = maxQ.top();
                
                maxQ.pop();
                m[temp]--;
            }
            else
            {
                cleanMin(minQ, m);
                temp = minQ.top();
                if(minQ.empty())
                    continue;
                
                minQ.pop();
                m[temp]--;
            }
        }
        
    }
    
    cleanMax(maxQ, m);
    cleanMin(minQ, m);
    
    if(maxQ.size() == 0 || minQ.size() == 0)
        return {0,0};
    
    return {maxQ.top(), minQ.top()};
}
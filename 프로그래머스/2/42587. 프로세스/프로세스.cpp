#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    stack<pair<int, int>> s;
    stack<pair<int, int>> temp;
    queue<pair<int, int>> q; //값, 식별
    
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(priorities[i], i));
    }
    
    while(!q.empty())
    {
        pair<int, int> taget = q.front();
        q.pop();
        
        vector<pair<int, int>> v;
        
        while(!temp.empty() && temp.top().first < taget.first)
        {
            v.push_back(temp.top());
            temp.pop();
        }
        temp.push(taget);
        while(!v.empty())
        {
            q.push(v.back());
            v.pop_back();
        }
    }
    
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    
    for(int i = 0; i < priorities.size(); i++)
    {
        if(s.top().second == location)
            return i + 1;
        s.pop();
    }
    
    return answer;
}
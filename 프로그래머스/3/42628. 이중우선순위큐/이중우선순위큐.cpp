#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    map<int, int> m;
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    
    for(string str : operations)
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
            bool end = false;
            
            if(maxQ.empty() || minQ.empty())
                continue;
            
            if(num == 1)
            {
                temp = maxQ.top();
                
                while(m[temp] == 0)
                {
                    maxQ.pop();

                    if(maxQ.size() == 0)
                    {
                        end = true;
                        break;
                    }

                    temp = maxQ.top();
                }
                
                if(!end)
                {
                    maxQ.pop();
                    m[temp]--;
                }
            }
            else
            {
                temp = minQ.top();
                
                while(m[temp] == 0)
                {
                    minQ.pop();

                    if(maxQ.size() == 0)
                    {
                        end = true;
                        break;
                    }

                    temp = minQ.top();
                }
                
                if(!end)
                {
                    minQ.pop();
                    m[temp]--;
                }
            }
        }
        
        while(m[maxQ.top()] == 0 && !maxQ.empty())
        {
            maxQ.pop();
        }
        
        while(m[minQ.top()] == 0 && !minQ.empty())
        {
            minQ.pop();
        }
        
        if(maxQ.size() == 0 || minQ.size() == 0)
        {
            maxQ = priority_queue<int>();
            minQ = priority_queue<int, vector<int>, greater<int>>();
        }
    }
    
    if(maxQ.size() == 0 || minQ.size() == 0)
        return {0,0};
    
    
    return {maxQ.top(), minQ.top()};
}
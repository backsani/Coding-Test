#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, priority_queue<string, vector<string>, greater<string>>> m;
    
    for(vector<string> ticket : tickets)
    {
        m[ticket[0]].push(ticket[1]);
    }
    
    vector<string> st;
    st.push_back("ICN");
    
    while(!st.empty())
    {
        string current = st.back();
        
        if(m[current].empty())
        {
            answer.push_back(current);
            st.pop_back();
        }
        else
        {
            string next = m[current].top();
            m[current].pop();
            st.push_back(next);
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
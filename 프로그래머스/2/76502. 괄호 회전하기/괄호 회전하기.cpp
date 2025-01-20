#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<char, int> m;
    m['['] = 0; m[']'] = 1; m['('] = 3; m[')'] = 4; m['{'] = 6; m['}'] = 7;
    
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i; j < i + s.size(); j++)
        {
            char c = s[j % s.size()];
            if(!st.empty() && m[st.top()] == m[c] - 1)
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
            
        }
        if(st.empty())
        {
            answer++;
        }
        
        st = stack<char>();
    }
    
    return answer;
}
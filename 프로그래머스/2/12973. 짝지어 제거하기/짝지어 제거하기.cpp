#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string str)
{
    int answer = -1;
    
    stack<char> s;
    
    for(char ch : str)
    {
        if(!s.empty() && s.top() == ch)
        {
            s.pop();
        }
        else
        {
            s.push(ch);
        }
    }
    
    answer = s.empty();

    return answer;
}
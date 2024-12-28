#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string my_string) {
    stack<char> s;
    string answer = "";
    
    for(char ch : my_string)
    {
        s.push(ch);
    }
    while(!s.empty())
    {
        answer += s.top();
        s.pop();
    }

    return answer;
}
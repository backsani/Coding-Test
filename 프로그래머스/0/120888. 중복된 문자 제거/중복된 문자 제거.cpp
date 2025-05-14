#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string my_string) {
    string answer = "";
    set<char> s;
    
    for(char ch : my_string)
    {
        if(s.find(ch) != s.end())
        {
            continue;
        }
        else
        {
            s.insert(ch);
            answer += ch;
        }
    }
    
    return answer;
}
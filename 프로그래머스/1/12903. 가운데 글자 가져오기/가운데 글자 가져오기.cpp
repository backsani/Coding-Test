#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool even = s.size() % 2 == 0;
    int len = even ? s.size() / 2 : s.size() / 2 + 1;
    int i = 0;
    
    for(char c : s)
    {
        ++i;
        if(i == len)
        {
            answer += c;
            if(even)
            {
                len++;
                even = !even;
            }
        }
    }
    return answer;
}
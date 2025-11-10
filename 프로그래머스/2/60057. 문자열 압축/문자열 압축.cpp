#include <string>
#include <vector>

using namespace std;

int splitStr(int length, string str)
{
    string answer = "";
    string prev = str.substr(0, length);
    int repit = 1;
    for(int i = length; i < str.size(); i += length)
    {
        string temp = str.substr(i, length);
        if(temp == prev)
        {
            repit++;
        }
        else
        {
            if(repit != 1)
                answer += to_string(repit);
            answer += prev;
            prev = temp;
            repit = 1;
        }
    }
    if(repit != 1)
        answer += to_string(repit);
    answer += prev;
    
    return answer.size();
}

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i < s.size(); i++)
    {
        int result = splitStr(i, s);
        answer = result < answer ? result : answer;
    }
    
    return answer;
}
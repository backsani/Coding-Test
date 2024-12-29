#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for(string str : s1)
    {
        for(string temp : s2)
        {
            if(str == temp)
                answer++;
        }
    }
    
    return answer;
}
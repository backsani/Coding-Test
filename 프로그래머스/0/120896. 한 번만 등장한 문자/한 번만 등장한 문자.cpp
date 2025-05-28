#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    
    map<char, int> m;
    
    for(char ch : s)
    {
        m[ch]++;
    }
    
    for(pair<char, int> p : m)
    {
        if(p.second == 1)
            answer += p.first;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
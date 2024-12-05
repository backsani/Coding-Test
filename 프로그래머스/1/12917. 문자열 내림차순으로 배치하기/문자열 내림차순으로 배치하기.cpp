#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<char> str;
    for(char c : s)
    {
        str.push_back(c);
    }
        
    sort(str.rbegin(), str.rend());
    
    string answer = "";
    for(char c : str)
    {
        answer += c;   
    }
    return answer;
}
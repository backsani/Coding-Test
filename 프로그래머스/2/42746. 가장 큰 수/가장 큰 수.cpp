#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i : numbers)
    {
        v.push_back(to_string(i));
    }
    sort(v.begin(), v.end(), [](string str1, string str2){
        return str1 + str2 > str2 + str1;
    });
    
    for(string str : v)
    {
        answer += str;
    }
    
    int zeroCount = 0;
    for(int i = 0; i < answer.length(); i++)
    {
        if(answer[i] == '0')
            zeroCount++;
        else
            break;
    }
    
    answer.substr(zeroCount, answer.length() - zeroCount);
    if(zeroCount == answer.length())
        return "0";
    
    return answer;
}
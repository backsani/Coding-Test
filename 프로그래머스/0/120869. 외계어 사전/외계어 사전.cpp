#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {   
    for(string& str : dic)
    {
        sort(str.begin(), str.end());
    }
    string temp = "";
    for(string str : spell)
    {
        temp += str;
    }
    sort(temp.begin(), temp.end());
    
    for(string str : dic)
    {
        auto it = str.find(temp);
        if(it != string::npos)
        {
            return 1;
        }
    }
    
    return 2;
}
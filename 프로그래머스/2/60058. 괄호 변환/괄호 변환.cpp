#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string changeStr(string str)
{
    str.erase(str.begin());
    str.erase(str.end() - 1);
    
    for(char& ch : str)
    {
        if(ch == '(')
            ch = ')';
        else
            ch = '(';
    }
    
    return str;
}

bool currectStr(string str)
{
    int countLeft = 0;
    int countRight = 0;
    
    for(char ch : str)
    {
        if(ch == '(')
            countLeft++;
        else
        {
            countRight++;
            if(countRight > countLeft)
                return false;
        }
    }
    return true;
}

string dfs(string v)
{
    if(v.empty())
        return "";
    
    string result;
    
    int countLeft = 0;
    int countRight = 0;
    
    string str1;
    string str2;
    
    for(char ch : v)
    {
        if(ch == '(')
            countLeft++;
        else if(ch == ')')
            countRight++;
        
        if(countLeft != 0 && countLeft == countRight)
        {
            str1 = string(v.begin(), v.begin() + countLeft + countRight);
            str2 = string(v.begin() + countLeft + countRight, v.end());
            break;
        }
    }
    
    bool currect = currectStr(str1);
    if(currect)
    {
        result = str1 + dfs(str2);
    }
    else
    {
        result = "(" + dfs(str2) + ")" + changeStr(str1);
    }
    
    return result;
}

string solution(string p) {
    return dfs(p);;
}
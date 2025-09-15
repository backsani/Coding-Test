#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    
    stringstream ss(polynomial);
    
    string str = "";
    
    int n = 0;
    int x = 0;
    
    bool oper = false;
    
    ss >> str;
    
    if(str.back() == 'x')
    {
        str = str.substr(0, str.size() - 1);
        if(str == "")
            str = "1";

        x += stoi(str);
    }
    else
    {
        n = stoi(str);
    }
    
    while(ss >> str)
    {
        if(str == "+")
        {
            ss >> str;

            if(str.back() == 'x')
            {
                str = str.substr(0, str.size() - 1);
                if(str == "")
                    str = "1";
                
                x += stoi(str);
            }
            else
            {
                n += stoi(str);
            }
        }
        else if(str == "x")
        {
            ss >> str;

            if(str.back() == 'x')
            {
                str = str.substr(0, str.size() - 1);
                if(str == "")
                    str = "1";
                
                x *= stoi(str);
            }
            else
            {
                n *= stoi(str);
            }
        }
    }
    
    if(x != 0)
    {
        if(x == 1)
            answer += "x";
        else
            answer += to_string(x) + "x";
    }
    if(n != 0)
    {
        if(answer != "")
        {
            answer += " + ";
        }
        answer += to_string(n);
    }
    
    return answer;
}
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
        bool plus;
        int *target;
        
        if(str == "+")
        {
            plus = true;
        }
        else
        {
            plus = false;
        }
        
        ss >> str;
        int temp;

        target = &n;
        if(str.back() == 'x')
        {
            target = &x;
            
            str = str.substr(0, str.size() - 1);
            if(str == "")
                str = "1";
        }
        temp = stoi(str);
        
        if(plus)
            *target += temp;
        else
            *target *= temp;
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
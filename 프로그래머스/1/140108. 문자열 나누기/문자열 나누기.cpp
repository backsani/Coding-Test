#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> result;
    
    string rStr = "";
    string xStr = "";
    string yStr = "";
    char x = '\0';
    
    for(char ch : s)
    {
        if(xStr == "" && x == '\0')
        {
            x = ch;
        }
        
        if(ch == x)
        {
            xStr += ch;
        }
        else
        {
            yStr += ch;
        }
        rStr += ch;
        
        if(xStr.size() == yStr.size())
        {
            result.push_back(rStr);
            rStr = "";
            xStr = "";
            yStr = "";
            x ='\0';
        }
    }
    if(rStr != "")
        result.push_back(rStr);
    
    return result.size();
}
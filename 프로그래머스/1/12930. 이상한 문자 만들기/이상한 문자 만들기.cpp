#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool even = true;
    
    for(char& c : s)
    {
        if(c == ' ')
        {
            even = true;
            continue;
        }
        if(even)
        {
            c = toupper(c);
        }
        else
        {
            c = tolower(c);
        }
        even = even ? false : true;
    }
    
    return s;
}
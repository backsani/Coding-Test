#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    bool upper;
    for(char& c : s)
    {
        if(c == ' ')
            continue;
        
        if(c >= 'a' && c <= 'z')
            upper = false;
        else
            upper = true;
        

        if(c + n > 'z')
            c -= 26 - n;
        
        else if(c + n > 'Z' && upper)
            c -= 26 - n;
        else
            c += n;
       
    }
    
    return s;
}
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool firstWord = true;
    
    for(char& ch : s)
    {
        if(ch == ' ')
        {
            firstWord = true;
        }
        else
        {
            if(firstWord)
            {
                ch = toupper(ch);
            }
            else
            {
                ch = tolower(ch);
            }
            firstWord = false;
        }
    }
    
    return s;
}
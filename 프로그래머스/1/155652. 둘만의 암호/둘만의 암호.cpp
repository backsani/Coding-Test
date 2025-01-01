#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0; i < index; i++)
    {
        for(char& ch : s)
        {
            if(++ch > 'z')
                ch = 'a';
            
            bool run = true;
            while(run)
            {
                run = false;
                for(char x : skip)
                {
                    if(x == ch)
                    {
                        if(++ch > 'z')
                            ch = 'a';
                        run = true;
                        break;
                    }

                }
            }
            

        }
    }
    
    
    return s;
}
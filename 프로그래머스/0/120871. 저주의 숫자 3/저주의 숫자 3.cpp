#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++)
    {
        answer++;
        
        if(answer % 3 == 0 || answer / 10 == 3 || answer % 10 == 3)
        {
            i--;
            continue;
        }
        
        string temp = to_string(answer);
        for(char ch : temp)
        {
            if(ch == '3')
            {
                i--;
                break;
            }
        }
            
    }
    
    return answer;
}
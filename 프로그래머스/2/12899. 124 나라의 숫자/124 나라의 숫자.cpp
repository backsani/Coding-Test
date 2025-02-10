#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n != 0)
    {
        int temp = n % 3;
        if(temp == 0)
        {
            temp = 4;
            n = n / 3 - 1;
        }
        else
            n /= 3;
            
        answer = to_string(temp) + answer;
        
    }
    
    return answer;
}
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    int count = 0;
    
    for(char ch : s)
    {
        if(ch == '(')
            count++;
        else
            count--;
        
        if(count < 0)
        {
            break;
        }
    }
    
    if(count == 0)
    {
        answer = true;
    }

    return answer;
}
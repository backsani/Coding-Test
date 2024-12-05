#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int plen = 0, ylen = 0;
    
    for(char c : s)
    {
        if(c == 'p' || c == 'P')
            plen++;
        else if(c == 'y' || c == 'Y')
            ylen++;
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return plen == ylen ? true : false;
}
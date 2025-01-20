#include <iostream>
using namespace std;

int solution(int n)
{
    //항상 1이 되기 위해 한번 점프하니 ans는 기본으로 1
    int ans = 1;
    int temp = 0;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    //짝수 일땐 2배 홀수일땐 한번 점프 후 2배
    //1이 나올때까지
    while(n != 1)
    {
        if(n % 2 != 0)
        {
            ans += 1;
        }
        n /= 2;
    }

    return ans;
}
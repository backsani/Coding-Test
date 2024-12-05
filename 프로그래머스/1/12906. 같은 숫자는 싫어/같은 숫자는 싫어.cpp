#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prevNum = -1;
    
    for(int i : arr)
    {
        if(prevNum != i)
        {
            prevNum = i;
            answer.push_back(i);
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
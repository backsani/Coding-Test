#include <string>
#include <vector>

using namespace std;

int numSize(int n)
{
    int result = 0;
    for(int i = n; i > 0; i--)
    {
        result += i;
    }
    return result;
}

vector<int> solution(int n) {
    int vSize = numSize(n);
    vector<int> answer(vSize, 0);
    
    int index = 0;
    int checkCount = 0;
    int state[3] = {0, 1, 2}; //0 : 아래로, 1 : 오른쪽으로 : 2 : 위로
    int stateIndex = 0;
    
    for(int i = 1; i <= vSize; i++)
    {
        answer[index] = i;
        
        switch(state[stateIndex])
        {
            case 0:
            {
                checkCount++;
                index += checkCount;
                if(index >= vSize || answer[index] != 0)
                {
                    stateIndex = (stateIndex + 1) % 3;
                    index -= checkCount;
                    index++;
                }
                break;
            }
            case 1:
            {
                index++;
                if(index >= vSize || answer[index] != 0)
                {
                    stateIndex = (stateIndex + 1) % 3;
                    index--;
                    index -= checkCount;
                }
                break;
            }
            case 2:
            {
                checkCount--;
                index -= checkCount;
                if(index < 0 || answer[index] != 0)
                {
                    stateIndex = (stateIndex + 1) % 3;
                    index += checkCount * 2;
                }
                break;
            }
                
        }
    }
    
    return answer;
}
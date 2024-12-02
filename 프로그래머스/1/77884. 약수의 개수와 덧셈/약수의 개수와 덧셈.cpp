#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i < right + 1; i++)
    {
        int count = 0;
        for(int j = 1; j < i + 1; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }
        answer += count % 2 == 0 ? i : i * -1;
    }
    
    return answer;
}
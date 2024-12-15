#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    
    for(int i = 1; i < number + 1; i++)
    {
        int count = 0;
        int compare = i;
        for(int j = 1; j * j <= i; j++)
        {
            if(j*j == i){
                count++;
            }
            else if(i % j == 0)
            {
                count += 2;
            }
        }
        
        if(count > limit)
            count = power;
        answer += count;
    }
    
    return answer;
}
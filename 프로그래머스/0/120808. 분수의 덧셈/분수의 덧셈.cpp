#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2,0);
    answer[0] = numer1 * denom2 + numer2 * denom1;
    answer[1] = denom1 * denom2;
    
    int prevA = answer[0];
    int prevB = answer[1];
    bool cd = true;
    while(prevA != 0 && prevB != 0)
    {
        int temp = prevB;
        
        prevB = prevA - prevB * (prevA / prevB);
        prevA = temp;
        
        if(prevA == 1 || prevB == 1)
        {
            cd = false;
            break;
        }
            
    }
    
    if(cd == true)
    {
        answer[0] /= prevA;
        answer[1] /= prevA;
    }
    
    return answer;
}
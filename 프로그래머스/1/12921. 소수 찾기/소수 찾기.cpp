#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<bool> num(n, true);
    num[0] = false;
    
    for(int i = 2; i < n + 1; i++)
    {
        int j = 2;
        
        while(i * j <= n)
        {
            num[i*j - 1] = false;
            j++;
        }
    }
    
    answer = count(num.begin(), num.end(), true);
    
    return answer;
}
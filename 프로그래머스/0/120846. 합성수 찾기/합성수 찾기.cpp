#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<bool> v(101, false);
    
    v[0] = true; v[1] = true;
    
    for(int i = 2; i < 101; i++)
    {
        if(v[i] == true)
            continue;
        
        int j = i + i;
        
        while(j < 101)
        {
            v[j] = true;
            j += i;
        }
    }
    
    for(int i = 4; i <= n; i++)
    {
        if(v[i] == true)
            answer++;
    }
    
    return answer;
}
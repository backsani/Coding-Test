#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 0;
    int temp = 0;
    
    vector<int> v;
    
    while(true)
    {
        if(temp > n)
        {
            temp -= v.front();
            
            v.erase(v.begin());
            continue;
        }
        else if(temp == n)
        {
            answer++;
            
        }
        i++;
        
        temp += i;
        v.push_back(i);
        
        if(i > n)
            break;
    }
    
    return answer;
}
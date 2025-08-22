#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> v(n+1, 0);
    
    v[0] = 1; v[1] = 1;
    
    for(int i = 2; i * i <= n; i++)
    {
        int j = i + i;
        
        while(j <= n)
        {
            v[j] = 1;
            j += i;
        }
    }
    
    for(int i = 2; i<= n; i++)
    {
        if(n % i == 0 && v[i] == 0)
        {
            answer.push_back(i);
        }
    }
    
    if(answer.size() == 0)
        answer.push_back(n);
    
    return answer;
}
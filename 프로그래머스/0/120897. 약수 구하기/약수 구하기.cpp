#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    map<int, int> m;
    
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            m[i] = 1;
            m[n / i] = 1;
        }
    }
    
    for(auto p : m)
    {
        answer.push_back(p.first);
    }
    
    return answer;
}
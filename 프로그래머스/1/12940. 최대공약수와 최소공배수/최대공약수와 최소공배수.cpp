#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calculComFac(vector<int>& v, int n)
{
    for(int i = 1; i < n + 1; i++)
    {
        if(n % i == 0)
            v.push_back(i);
    }
    
    return v;
}

vector<int> solution(int n, int m) {
    vector<int> answer(2,0);
    vector<int> minComFac;
    vector<int> maxComMea;

    if(n < m)
    {
        int temp = 0;
        temp = n;
        n = m;
        m = temp;
    }
    
    calculComFac(minComFac, n);
    calculComFac(minComFac, m);
    
    sort(minComFac.begin(), minComFac.end());
    
    int prevNum = 0;
    int minComFacNum = 0;
    for(int& i : minComFac)
    {
        if(prevNum != i)
        {
            prevNum = i;
            i = 0;
        }
    }
    sort(minComFac.begin(), minComFac.end());
    
    answer[0] = minComFac.back();
    
    int prevN = n;
    int prevM = m;
    while(true)
    {
        if(n < m)
        {
            n += prevN;
        }
        
        if(n == m)
        {
            answer[1] = n;
            break;
        }
            
        m += prevM;
    }
    
    return answer;
}
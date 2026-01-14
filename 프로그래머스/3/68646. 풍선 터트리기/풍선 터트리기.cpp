#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int bIndex = 0;
    
    map<int, bool> m;
    for(int n : a)
    {
        m[n] = true;
    }
    
    int leftMin = 1000000001;
    int rightMin = b[bIndex];
    
    for(int i = 0; i < a.size(); i++)
    {
        int n = a[i];
        m[n] = false;
        
        if(n == rightMin)
        {
            while(m[rightMin] == false)
            {
                ++bIndex;
                if(bIndex == b.size())
                {
                    rightMin = 1000000001;
                    break;
                }
                    
                rightMin = b[bIndex];
            }
        }
        
        if(leftMin < n && rightMin < n)
            ;
        else
            answer++;
        leftMin = min(leftMin, n);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int maxCount = 0;
    vector<int> v;
    
    map<int, int> m;
    
    for(int i : array)
        m[i]++;
    
    for(pair<int, int> p : m)
    {
        if(p.second >= maxCount)
        {
            if(p.second == maxCount)
            {
                v.push_back(p.first);
                continue;
            }
            v = vector<int>();
            v.push_back(p.first);
            maxCount = p.second;
        }
    }
    
    if(v.size() > 1)
        return -1;
    
    return v[0];
}
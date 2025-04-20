#include <string>
#include <vector>
#include <map>
#include <set>
#include <climits>

using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> m;
    vector<vector<int>> results;
    
    set<string> s;
    for(string str : gems)
        s.insert(str);
    int gemsCount = s.size();
    
    int start = 0;
    string frontGem = gems[0];
    
    int current = 0;
    bool firstFind = false;
    
    for(int i = 0; i < gems.size(); i++)
    {
        current = i;
        m[gems[i]]++;
        
        if(m.size() == gemsCount && !firstFind)
        {
            results.push_back({start + 1, current + 1});
            firstFind = true;
        }
        
        bool init = false;
        
        while(m[frontGem] > 1)
        {
            start++;
            m[frontGem]--;
            frontGem = gems[start];
            init = true;
        }
        
        if(firstFind && init)
            results.push_back({start + 1, current + 1});
    }
    
    int temp = INT_MAX;
    vector<int> result;
    for(vector<int> v : results)
    {
        if(temp > v[1] - v[0])
        {
            temp = v[1] - v[0];
            result = v;
        }
    }
    
    return result;
}
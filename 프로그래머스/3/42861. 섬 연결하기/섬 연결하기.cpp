#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });
    
    vector<vector<int>> groups;
    
    for(vector<int> v : costs)
    {
        bool conect = false;
        bool newIsland = true;
        int index = -1;
        
        for(int i = 0; i < groups.size(); i++)
        {
            auto g0 = find(groups[i].begin(), groups[i].end(), v[0]);
            auto g1 = find(groups[i].begin(), groups[i].end(), v[1]);
            
            if (g0 != groups[i].end() && g1 != groups[i].end())
            {
                newIsland = false;
                continue;
            }
            if(g0 != groups[i].end())
            {
                if(conect)
                {
                    groups[i].insert(groups[i].end(), groups[index].begin(), groups[index].end());
                    groups.erase(groups.begin() + index);
                    break;
                }
                
                newIsland = false;
                groups[i].push_back(v[1]);
                answer += v[2];
                conect = true;
                index = i;
            }
            else if(g1 != groups[i].end())
            {
                if(conect)
                {
                    groups[i].insert(groups[i].end(), groups[index].begin(), groups[index].end());
                    groups.erase(groups.begin() + index);
                    break;
                }
                
                newIsland = false;
                groups[i].push_back(v[0]);
                answer += v[2];
                conect = true;
                index = i;
            }
        }
        
        if(newIsland)
        {
            vector<int> temp;
            temp.push_back(v[0]);
            temp.push_back(v[1]);
            answer += v[2];
            
            groups.push_back(temp);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    
    int index = 1;
    
    for(int i = 0; i < genres.size(); i++)
    {
        if(m[genres[i]] == 0)
        {
            m[genres[i]] = index;
            index++;
        }
    }
    
    vector<pair<int, vector<int>>> group(index, {0, {}});
    vector<int> sum(index, 0);
    
    for(int i = 0; i < genres.size(); i++)
    {
        int temp = m[genres[i]];
        group[temp].second.push_back(i);
        group[temp].first += plays[i];
    }
    
    sort(group.begin(), group.end(), [](auto& a, auto& b){
        return a.first > b.first;
    });
    
    for(auto& [i, v] : group)
    {
        if(v.empty())
            continue;
        
        sort(v.begin(), v.end(), [plays](int a, int b){
            if(plays[a] != plays[b])
                return plays[a] > plays[b];
            else
                return a < b;
        });
        
        answer.push_back(v[0]);
        if(v.size() >= 2)
            answer.push_back(v[1]);
    }
    
    //return {group[0].first};
    return answer;
}
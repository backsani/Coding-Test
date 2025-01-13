#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, int> id;
    for(int i = 0; i < id_list.size(); i++)
    {
        id[id_list[i]] = i;
    }
    
    vector<vector<string>> v(id_list.size());
    map<string, int> m;
    
    for(string str : id_list)
    {
        m[str] = 0;
    }
    
    for(string str : report)
    {
        string from;
        string to;
        stringstream ss(str);
        ss >> from >> to;
        
        if(find(v[id[to]].begin(), v[id[to]].end(), from) != v[id[to]].end())
        {
            continue;
        }
        m[to]++;
        v[id[to]].push_back(from);
    }
    
    for(string str : id_list)
    {
        if(m[str] >= k)
        {
            for(string from : v[id[str]])
            {
                answer[id[from]]++;
            }
        }
    }
    
    return answer;
}
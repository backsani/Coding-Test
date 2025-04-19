#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs(vector<vector<int>> banList)
{
    queue<pair<set<int>, int>> q;
    set<int> s;
    
    q.push({s, 0});
    
    while(!q.empty())
    {
        pair<set<int>, int> current = q.front();
        
        
        int index = current.second;
        
        if(index == banList.size())
            break;
        
        q.pop();
        
        for(int i : banList[index])
        {
            set<int> temp = current.first;
            temp.insert(i);
            
            if(current.first.size() == temp.size())
                continue;
            
            q.push({temp, index + 1});
        }
    }
    
    set<set<int>> sv;
    
    while(!q.empty())
    {
        pair<set<int>, int> temp = q.front();
        sv.insert(temp.first);
        q.pop();
    }
    
    return sv.size();
}

bool checkBan(string str1, string str2)
{
    if(str1.size() != str2.size())
        return false;
    
    for(int i = 0; i < str1.size(); i++)
    {
        if(str2[i] == '*')
            continue;
        
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<vector<int>> v(banned_id.size(), vector<int>());
    
    for(int i = 0; i < banned_id.size(); i++)
    {
        for(int j = 0; j < user_id.size(); j++)
        {
            if(checkBan(user_id[j], banned_id[i]))
            {
                v[i].push_back(j);
            }
        }
    }
    
    return bfs(v);
    //return v[1][0];
}
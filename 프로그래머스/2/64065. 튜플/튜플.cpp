#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

void makeGroup(string str, vector<int>& v)
{
    stringstream ss(str);
    string temp;
    
    while(getline(ss, temp, ','))
    {
        v.push_back(stoi(temp));
    }
}

vector<int> solution(string str) {
    vector<int> answer;
    vector<vector<int>> v;
    set<int> s;
    
    int start = 0;
    int end = 0;
    
    for(int i = 0; i < str.size() - 1; i++)
    {
        if(str[i] == '{')
            start = i;
        if(str[i] == '}')
        {
            end = i;
            string group = str.substr(start + 1, end - start - 1);
            vector<int> temp;
            makeGroup(group, temp);
            v.push_back(temp);
        }
    }
    
    sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b){
        return a.size() < b.size();
    });
    
    for(vector<int> group : v)
    {
        for(int i : group)
        {
            auto it = s.find(i);
            if(it == s.end())
            {
                answer.push_back(i);
                s.insert(i);
            }
        }
    }
    
    return answer;
}
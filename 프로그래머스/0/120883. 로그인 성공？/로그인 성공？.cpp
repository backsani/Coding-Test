#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    map<string, string> m;
    
    for(vector<string> v : db)
    {
        m[v[0]] = v[1];
    }
    
    if(m.find(id_pw[0]) != m.end())
    {
        if(m[id_pw[0]] == id_pw[1])
        {
            answer = "login";
        }
        else
        {
            answer = "wrong pw";
        }
    }
    else
    {
        answer = "fail";
    }
    
    return answer;
}
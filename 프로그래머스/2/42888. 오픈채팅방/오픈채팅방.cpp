#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    //State와 id를 저장
    vector<pair<string, string>> v;
    
    //string : id, string : name
    map<string, string> m;
    
    //for문이 끝나면 최종 id와 그에 맞는 name이 저장된다.
    for(string str : record)
    {
        //공백을 기준으로 문자열을 나누어준다.
        stringstream ss(str);
        string state;
        string id;
        string name;
        
        //나눈 문자열을 차례대로 state, id, name에 저장한다.
        ss >> state >> id >> name;
        
        //state와 id를 순서대로 저장한다.
        v.push_back(make_pair(state, id));
        
        //이름 변경은 Enter, Change에서만 변경되기에 이때만 이름 변경
        if(state == "Enter" || state == "Change")
        {
            //id는 바뀌지 않으니 id를 키 값으로 이름을 저장한다.
            m[id] = name;
        }
    }
    
    for(pair<string, string> p : v)
    {
        if(p.first == "Enter")
        {
            answer.push_back(m[p.second] + "님이 들어왔습니다.");
        }
        else if(p.first == "Leave")
        {
            answer.push_back(m[p.second] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}
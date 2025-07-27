#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0,0};
    
    map<string, vector<int>> m;
    m["up"] = { 0 , 1 }; m["down"] = {0,-1}; m["left"] = {-1, 0}; m["right"] = {1,0};
    
    for(string str : keyinput)
    {
        vector<int> nv = answer;
        nv[0] = nv[0] + m[str][0];
        nv[1] = nv[1] + m[str][1];
        
        if(abs(nv[0]) > board[0] / 2 || abs(nv[1]) > board[1] / 2)
            continue;
        
        answer = nv;
    }
    
    return answer;
}
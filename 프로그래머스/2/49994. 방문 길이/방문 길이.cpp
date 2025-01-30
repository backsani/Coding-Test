#include <string>
#include <set>
#include <map>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    map<char, pair<int, int>> m;
    m['U'] = {0, 1}; m['D'] = {0, -1}; m['L'] = {-1, 0}; m['R'] = {1, 0}; 
    set<pair<pair<int, int>, pair<int, int>>> s;
    pair<int, int> currentPos = make_pair(0,0);
    
    for(char ch : dirs)
    {
        int nx = currentPos.first + m[ch].first;
        int ny = currentPos.second + m[ch].second;
        
        if(nx > 5 || ny > 5 || nx < -5 || ny < -5)
            continue;
        
        s.insert({currentPos, {nx, ny}});
        s.insert({{nx, ny}, currentPos});
        
        currentPos = {nx, ny};
    }
    
    return s.size() / 2;
}
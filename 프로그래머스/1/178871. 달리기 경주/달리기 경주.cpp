#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int i = 0;
    
    map<string, int> m;
    
    for(int i = 0; i < players.size(); i++)
    {
        m[players[i]] = i;
    }
    
    for(string str : callings)
    {
        int index = m[str];
        
        swap(players[index], players[index - 1]);
        m[players[index]] = index;
        m[players[index - 1]] = index - 1;
        
    }
    
    
    return players;
}
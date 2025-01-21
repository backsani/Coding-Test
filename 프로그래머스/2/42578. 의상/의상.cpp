#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, vector<string>> m;
    
    for(vector<string> v : clothes)
    {
        m[v[1]].push_back(v[0]);
    }
    
    int temp = 1;
    for(pair<string, vector<string>> p : m)
    {
        
        temp *= p.second.size() + 1;
        
    }
    
    return temp - 1;
}
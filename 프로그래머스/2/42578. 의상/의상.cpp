#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, vector<string>> m;
    set<string> s;
    
    for(const vector<string> clothe : clothes)
    {
        m[clothe[1]].push_back(clothe[0]);
        s.insert(clothe[1]);
    }
    
    for(string str : s)
    {
        int num = m[str].size();
        answer *= num + 1;
    }
    
    return answer - 1;
}
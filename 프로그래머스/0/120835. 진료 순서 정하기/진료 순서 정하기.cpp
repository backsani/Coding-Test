#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size(), 0);
    
    //수치, 순번
    vector<pair<int, int>> v;
    
    int count = 1;
    for(int i : emergency)
    {
        v.push_back({i, count++});
    }
    
    sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    });
    
    for(int i = 1; i <= v.size(); i++)
    {
        answer[v[i-1].second-1] = i;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> m;
    m["code"] = 0; m["date"] = 1; m["maximum"] = 2; m["remain"] = 3;
    
    for(vector<int> v : data)
    {
        if(v[m[ext]] < val_ext)
        {
            answer.push_back(v);
        }
    }
    
    sort(answer.begin(), answer.end(), [sort_by, &m](const vector<int>& answer1, const vector<int>& answer2) {
        return answer1[m.at(sort_by)] < answer2[m.at(sort_by)]; // 내림차순 정렬
    });
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer(num_list.size() / n, vector<int>(n, 0));
    
    auto it = num_list.begin();
    
    for(vector<int> &v : answer)
    {
        for(int &i : v)
        {
            i = *it++;
        }
    }
    
    return answer;
}
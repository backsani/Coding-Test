#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    answer = num_list;
    
    sort(answer.begin(), answer.end());
    answer.erase(answer.begin(), answer.begin() + 5);
    
    return answer;
}
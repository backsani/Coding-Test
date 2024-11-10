#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reverse(string n, int i, int j){
    string result = n.substr(i, j - i + 1);;
    std::reverse(result.begin(), result.end());
    return result;
}

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    
    answer = my_string;
    for(const vector<int> n : queries){
        answer.replace(n[0], n[1] - n[0] + 1, reverse(answer, n[0], n[1]));
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    for(int i{}; i < n; i++){
        answer += my_string[i];
    }
    return answer;
}
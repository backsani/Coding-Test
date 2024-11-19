#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int n) {
    string answer = "";
    int i = 0;
    int j = 0;
    
    for(char c : my_string){
        i++;
        j++;
        if(j == n)
            answer += c;
        if(i == m){
            i = 0;
            j = 0;
        }
    }
    
    return answer;
}
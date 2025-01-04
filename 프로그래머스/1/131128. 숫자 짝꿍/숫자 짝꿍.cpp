#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.rbegin(), X.rend());
    sort(Y.rbegin(), Y.rend());
    
    int x = 0, y = 0;
    
    while(!(x == X.size() || y == Y.size()))
    {
        if(X[x] == Y[y])
        {
            answer += X[x];
            x++, y++;
            
        }
        else
        {
            X[x] > Y[y] ? x++ : y++;
        }
    }
    
    if(answer.empty())
        answer = "-1";
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    string a, b, op;
    int trans = 1;
    
    for(char c : binomial){
        if(c == ' '){
            trans++;
        }
        else if(trans == 1){
            a += c;
        }
        else if(trans == 2){
            op += c;
        }
        else if(trans == 3){
            b += c;
        }
    }
    
    if(op == "+"){
        answer = stoi(a) + stoi(b);
    }
    else if(op == "-"){
        answer = stoi(a) - stoi(b);
    }
    else if(op == "*"){
        answer = stoi(a) * stoi(b);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    int a, b;
    char op;
    
    stringstream ss;
    ss.str(binomial);
    ss >> a >> op >> b;
    
    
    if(op == '+'){
        answer = (a) + (b);
    }
    else if(op == '-'){
        answer = (a) - (b);
    }
    else if(op == '*'){
        answer = (a) * (b);
    }
    
    return answer;
}
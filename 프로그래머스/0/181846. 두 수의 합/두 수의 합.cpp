#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    bool up = false;
    string result = "";
    
    while(a.size() != b.size()){
        if(a.size() > b.size()){
            b = "0" + b;
        }
        else{
            a = "0" + a;
        }
    }
    
    for(int i = a.size() - 1; i >= 0; i--){
        result = to_string((a[i] - '0') + (b[i] - '0') + (up ? 1 : 0));
        up = false;
        if(stoi(result) >= 10){
            result = to_string(stoi(result) - 10);
            up = true;
        }
        answer = result + answer;
    }
    if(up){
        answer = "1" + answer;
    }
    
    return answer;
}
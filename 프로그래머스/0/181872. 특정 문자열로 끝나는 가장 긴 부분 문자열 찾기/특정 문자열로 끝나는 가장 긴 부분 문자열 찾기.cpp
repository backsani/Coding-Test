#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    int length = 0;
    
    for(int i{}; i < myString.size(); i++){
        int pos = myString.find(pat,i);
        length = pos != string::npos ? pos : length;
    }
    
    for(int i{}; i < length + pat.size(); i++){
        answer += myString[i];
    }
    
    return answer;
}
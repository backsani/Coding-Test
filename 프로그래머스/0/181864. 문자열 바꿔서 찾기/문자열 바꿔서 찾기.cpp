#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    string answer = "";
    
    for(char n : myString){
        answer += n == 'A' ? "B" : "A";
    }
    
    return answer.find(pat) != string::npos;
}
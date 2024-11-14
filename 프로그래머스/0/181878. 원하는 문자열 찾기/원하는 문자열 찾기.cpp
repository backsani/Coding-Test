#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    string a = "";
    string b = "";
    
    for(char str : myString){
        a += tolower(str);        
    }
    for(char str : pat){
        b += tolower(str);
    }
    
    answer = a.find(b) == string::npos ? 0 : 1;
    return answer;
}
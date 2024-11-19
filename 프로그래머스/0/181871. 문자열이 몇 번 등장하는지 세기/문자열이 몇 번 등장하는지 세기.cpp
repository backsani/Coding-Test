#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    int i = 0;
    
    while(myString != ""){
        for(int j = 0; j < pat.size(); j++){
            if(myString[j] != pat[j]) break;
            if(j == pat.size() - 1) answer++;
        }
        myString.erase(0,1);
        i++;
    }
    return answer;
}
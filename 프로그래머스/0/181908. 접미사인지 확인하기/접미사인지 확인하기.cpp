#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    vector<string> result;
    
    for(int i = 0; i < my_string.size(); i++){
        result.push_back(my_string.substr(i));
    }
    
    for(string n : result){
        if(n == is_suffix)
            return 1;
    }
    
    return answer;
}
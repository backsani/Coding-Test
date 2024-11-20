#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    vector<int> strlen(30);
    int answer = 0;
    int max = 0;
    
    for(string str : strArr){
        strlen[str.size() - 1]++;
    }
    
    for(int n : strlen){
        max = max < n ? n : max;
    }
    
    return max;
}
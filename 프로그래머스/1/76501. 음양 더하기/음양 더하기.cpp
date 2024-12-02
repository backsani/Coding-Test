#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    int result = 0;
    
    for(int i = 0; i < signs.size(); i++)
    {
        result += signs[i] ? absolutes[i] : absolutes[i] * -1;
    }
    
    return result;
}
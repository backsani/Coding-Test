#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string number = to_string(x);
    int sum = 0;
    
    for(char c : number)
    {
        sum += c - '0';
    }
    
    return x % sum == 0 ? true : false;
}
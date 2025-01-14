#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = n;
    bitset<32> binary(n);
    string str = binary.to_string();
   
    string temp = "0";
    
    while(count(str.begin(), str.end(), '1') != count(temp.begin(), temp.end(), '1'))
    {
        n += 1;
        bitset<32> binary(n);
        temp = binary.to_string();
    }
    
    
    return n;
}
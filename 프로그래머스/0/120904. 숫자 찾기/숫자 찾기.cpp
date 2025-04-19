#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int num, int k) {
    string s = to_string(num);          
    size_t pos = s.find(k + '0');      

    if (pos == string::npos) return -1;
    return pos + 1;                     
}

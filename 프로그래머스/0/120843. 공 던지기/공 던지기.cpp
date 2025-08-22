#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int target = 0;
    
    for(int i = k - 1; i > 0; i--)
    {
        target = (target + 2) % numbers.size();
    }
    
    return numbers[target];
}
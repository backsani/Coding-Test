#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for(int& num : numbers)
    {
        num *= 2;
    }
    return numbers;
}
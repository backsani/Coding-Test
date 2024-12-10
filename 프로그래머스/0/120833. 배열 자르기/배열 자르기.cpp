#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> v;
    for(int i = num1; i < num2 + 1; i++)
    {
        v.push_back(numbers[i]);
    }
    
    return v;
}
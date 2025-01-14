#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    vector<int> numbers;
    int i;
    
    while(ss >> i)
    {
        numbers.push_back(i);
    }
    int max = *max_element(numbers.begin(),numbers.end());
    int min = *min_element(numbers.begin(),numbers.end());
    
    return to_string(min) + " " + to_string(max);
}
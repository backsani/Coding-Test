#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(min_element(arr.begin(), arr.end()));
    vector<int> v = arr;
    return v.empty() ? vector<int>(1,-1) : v;
}
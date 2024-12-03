#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> v = arr;
    sort(v.rbegin(), v.rend());
    arr.erase(remove(arr.begin(), arr.end(), v.back()), arr.end());
    if(arr.empty())
        arr.push_back(-1);
    return arr;
}
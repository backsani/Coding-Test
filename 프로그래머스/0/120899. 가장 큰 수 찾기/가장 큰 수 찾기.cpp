#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    auto maxIndex = max_element(array.begin(), array.end());
    
    return {*maxIndex, (int)(maxIndex - array.begin())};
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxV = 0;
    int maxH = 0;
    
    for(vector<int> v : sizes)
    {
        sort(v.begin(), v.end());
        maxV = maxV < v[0] ? v[0] : maxV;
        maxH = maxH < v[1] ? v[1] : maxH;
    }
    
    return maxV * maxH;
}
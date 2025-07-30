#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    sort(numlist.begin(), numlist.end(), [n](int &a, int &b){
        int diffA = abs(n - a);
        int diffB = abs(n - b);
        if(diffA == diffB)
            return a > b;
        return diffA < diffB;
    });
    
    return numlist;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    if (scores.size() == 1) 
        return 1;

    vector<int> wanho = scores[0];
    int wanhoSum = wanho[0] + wanho[1];

    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) 
            return a[1] < b[1];
        return a[0] > b[0];
    });

    int rank = 1;
    int maxSecond = -1;

    for (const auto& s : scores) 
    {
        int a = s[0];
        int b = s[1];

        if (a > wanho[0] && b > wanho[1]) 
            return -1;

        if (b < maxSecond) 
            continue;

        maxSecond = b;

        if (a == wanho[0] && b == wanho[1]) 
            continue;

        if (a + b > wanhoSum) 
            rank++;
    }

    return rank;
}

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 
    });

    int answer = 0;
    double lastIntercept = -1;

    for (const auto& missile : targets) {
        int s = missile[0];
        int e = missile[1];

        if (lastIntercept < s) {
            lastIntercept = e - 0.1; 
            answer++;
        }
    }

    return answer;
}

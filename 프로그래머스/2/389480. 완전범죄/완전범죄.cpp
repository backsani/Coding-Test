#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 1e9;

    // dp[b] = B 흔적이 b일 때 A 흔적 최소
    vector<int> dp(m, INF);
    dp[0] = 0;

    for (auto &it : info) {
        int aCost = it[0];
        int bCost = it[1];

        vector<int> ndp(m, INF);

        for (int b = 0; b < m; b++) {
            if (dp[b] == INF) continue;

            // 1) A가 훔치는 경우: A 증가, B 동일
            int na = dp[b] + aCost;
            if (na < n) {
                ndp[b] = min(ndp[b], na);
            }

            // 2) B가 훔치는 경우: B 증가, A 동일
            int nb = b + bCost;
            if (nb < m) {
                ndp[nb] = min(ndp[nb], dp[b]);
            }
        }

        dp.swap(ndp);
    }

    int ans = *min_element(dp.begin(), dp.end());
    return (ans == INF) ? -1 : ans;
}
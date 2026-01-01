#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 1e9;

    vector<int> dp(m, INF);
    dp[0] = 0;

    for (auto &it : info) {
        int aCost = it[0];
        int bCost = it[1];

        vector<int> ndp(m, INF);

        for (int b = 0; b < m; b++) {
            if (dp[b] == INF) continue;

            int na = dp[b] + aCost;
            if (na < n) {
                ndp[b] = min(ndp[b], na);
            }

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
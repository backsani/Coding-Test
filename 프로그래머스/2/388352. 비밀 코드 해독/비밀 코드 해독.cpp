#include <vector>

using namespace std;

void dfsAllCodes(int n, int start, vector<int>& cur, vector<vector<int>>& out) {
    if (cur.size() == 5) {
        out.push_back(cur);
        return;
    }

    for (int x = start; x <= n; x++) {
        int remaining = n - x + 1;
        int need = 5 - cur.size();
        if (remaining < need) break;

        cur.push_back(x);
        dfsAllCodes(n, x + 1, cur, out);
        cur.pop_back();
    }
}

int intersectionCount(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, cnt = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            cnt++;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<vector<int>> lists;
    lists.reserve(150000);

    vector<int> cur;
    dfsAllCodes(n, 1, cur, lists);

    for (int i = 0; i < q.size(); i++) {
        vector<vector<int>> next;
        next.reserve(lists.size());

        for (const auto& cand : lists) {
            if (intersectionCount(cand, q[i]) == ans[i]) {
                next.push_back(cand);
            }
        }
        lists.swap(next);
    }

    return lists.size();
}

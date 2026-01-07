#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(const string& s)
{
    int n = (int)s.size();
    if (n == 0) return 0;

    int maxLen = 1;
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++)
        q.push({i, i});

    for (int i = 0; i + 1 < n; i++)
        if (s[i] == s[i + 1])
            q.push({i, i + 1});

    while (!q.empty())
    {
        auto [l, r] = q.front();
        q.pop();

        maxLen = max(maxLen, r - l + 1);

        int nl = l - 1;
        int nr = r + 1;
        if (nl < 0 || nr >= n) 
            continue;
        if (s[nl] != s[nr]) 
            continue;

        q.push({nl, nr});
    }

    return maxLen;
}

int solution(string s)
{
    return bfs(s);
}
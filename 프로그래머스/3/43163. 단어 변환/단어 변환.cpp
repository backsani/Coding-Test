#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

int bfs(string begin, string target, vector<vector<string>>& key, map<string, int>& m)
{
    queue<pair<string, int>> q;
    set<string> visited;

    q.push({begin, 0}); // ✅ 처음엔 depth 0부터 시작
    visited.insert(begin);

    while (!q.empty())
    {
        string current = q.front().first;
        int depth = q.front().second;
        q.pop();

        for (string next : key[m[current]])
        {
            if (visited.count(next)) continue;
            if (next == target) return depth + 1;

            visited.insert(next);
            q.push({next, depth + 1});
        }
    }

    return 0;
}

int diffWord(string str1, string str2)
{
    int length = str1.size();
    int sameCount = 0;
    for(int k = 0; k < length; k++)
    {
        if(str1[k] == str2[k])
            sameCount++;
    }
    return length - sameCount;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) return 0;

    words.push_back(begin); // 🔥 begin도 그래프에 포함
    map<string, int> m;
    int pos = 0;

    for (string word : words)
    {
        m[word] = pos++;
    }

    vector<vector<string>> key(words.size());

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (i == j) continue;
            if (diffWord(words[i], words[j]) == 1)
                key[i].push_back(words[j]);
        }
    }

    return bfs(begin, target, key, m);
}
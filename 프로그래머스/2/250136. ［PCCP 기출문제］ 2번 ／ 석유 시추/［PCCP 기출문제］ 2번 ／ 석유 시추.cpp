#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void scan(pair<int, int> pos, vector<vector<int>>& land, int oilId, vector<vector<pair<int, int>>>& oils)
{
    queue<pair<int, int>> q;
    q.push(pos);

    vector<pair<int, int>> bundle;
    bundle.push_back(pos);

    int oilsCount = 1;
    oils[pos.first][pos.second] = {oilId, 0}; // mark visited

    pair<int, int> direction[4] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    while (!q.empty())
    {
        pair<int, int> currentPos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = currentPos.second + direction[i].second;
            int ny = currentPos.first + direction[i].first;

            if (nx < 0 || nx >= land[0].size() || ny < 0 || ny >= land.size())
                continue;

            if (land[ny][nx] == 1 && oils[ny][nx].first == 0)
            {
                q.push({ny, nx});
                bundle.push_back({ny, nx});
                oils[ny][nx] = {oilId, 0}; // visited mark
                oilsCount++;
            }
        }
    }

    for (auto& p : bundle)
    {
        oils[p.first][p.second] = {oilId, oilsCount};
    }
}

int solution(vector<vector<int>> land) {
    int oilId = 1;
    int n = land.size();
    int m = land[0].size();
    vector<vector<pair<int, int>>> oils(n, vector<pair<int, int>>(m, {0, 0}));

    int maxOils = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 1 && oils[i][j].first == 0)
            {
                scan({i, j}, land, oilId, oils);
                oilId++;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        set<int> visited_ids;
        int oil = 0;

        for (int i = 0; i < n; i++)
        {
            int id = oils[i][j].first;
            int size = oils[i][j].second;

            if (id != 0 && visited_ids.count(id) == 0)
            {
                oil += size;
                visited_ids.insert(id);
            }
        }

        maxOils = max(maxOils, oil);
    }

    return maxOils;
}

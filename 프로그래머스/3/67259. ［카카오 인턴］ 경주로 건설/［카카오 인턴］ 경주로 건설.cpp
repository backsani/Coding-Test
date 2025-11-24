#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int cost;
    int y;
    int x;
    int dir;
    bool operator>(const Node& other) const 
    {
        return cost > other.cost;
    }
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    int INF = 1e9;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<vector<int>>> cost(
        n, vector<vector<int>>(n, vector<int>(4, INF))
    );

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int dir = 0; dir < 4; ++dir) 
    {
        int ny = dy[dir];
        int nx = dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) 
            continue;
        if (board[ny][nx] == 1) 
            continue;
        cost[ny][nx][dir] = 100;
        pq.push({100, ny, nx, dir});
    }

    while (!pq.empty()) 
    {
        Node cur = pq.top();
        pq.pop();

        if (cur.cost > cost[cur.y][cur.x][cur.dir]) 
            continue;

        for (int ndir = 0; ndir < 4; ++ndir) 
        {
            int ny = cur.y + dy[ndir];
            int nx = cur.x + dx[ndir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) 
                continue;
            if (board[ny][nx] == 1) continue;

            int add = (ndir == cur.dir) ? 100 : 600;
            int nextCost = cur.cost + add;

            if (nextCost < cost[ny][nx][ndir]) 
            {
                cost[ny][nx][ndir] = nextCost;
                pq.push({nextCost, ny, nx, ndir});
            }
        }
    }

    int answer = INF;
    for (int d = 0; d < 4; ++d) 
    {
        answer = min(answer, cost[n-1][n-1][d]);
    }

    return answer;
}

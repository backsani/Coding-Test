#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1); // 그래프 표현
    vector<int> distance(N + 1, INT_MAX); // 최단 거리 테이블
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // 그래프 초기화
    for (const auto& r : road) {
        graph[r[0]].emplace_back(r[1], r[2]);
        graph[r[1]].emplace_back(r[0], r[2]);
    }

    // 다익스트라 알고리즘
    distance[1] = 0; // 시작점
    pq.emplace(0, 1); // 시작점 큐에 추가

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist > distance[now]) continue; // 이미 처리된 경우 건너뜀

        for (const auto& next : graph[now]) {
            int cost = dist + next.second; // 현재 거리 + 이동 거리

            if (cost < distance[next.first]) { // 더 짧은 경로 발견 시
                distance[next.first] = cost;
                pq.emplace(cost, next.first);
            }
        }
    }

    // K 이하로 갈 수 있는 마을 개수 세기
    return count_if(distance.begin(), distance.end(), [K](int d) { return d <= K; });
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1); // 그래프 표현 (인접 리스트)
    vector<int> distance(N + 1, INT_MAX); // 최단 거리 테이블 (무한대로 초기화)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    // 우선순위 큐 (거리, 노드 번호) - 거리가 짧은 순으로 정렬

    // 그래프 초기화: 도로 정보를 바탕으로 그래프(인접 리스트)를 구성
    for (const auto& r : road) {
        graph[r[0]].emplace_back(r[1], r[2]); // a -> b, 시간 c
        graph[r[1]].emplace_back(r[0], r[2]); // b -> a (양방향)
    }

    // 다익스트라 알고리즘
    distance[1] = 0; // 시작점 (1번 마을)의 거리는 0
    pq.emplace(0, 1); // 시작점을 우선순위 큐에 추가 (거리 0, 노드 1)

    // 큐가 빌 때까지 반복
    while (!pq.empty()) {
        int dist = pq.top().first; // 현재 노드까지의 최단 거리
        int now = pq.top().second; // 현재 노드 번호
        pq.pop(); // 큐에서 제거

        // 이미 처리된 경우 (더 짧은 경로가 이미 발견된 경우) 건너뜀
        if (dist > distance[now]) continue;

        // 현재 노드와 연결된 다른 노드들을 탐색
        for (const auto& next : graph[now]) {
            int cost = dist + next.second; // 현재 노드를 거쳐 다음 노드로 가는 비용

            // 더 짧은 경로를 발견한 경우
            if (cost < distance[next.first]) {
                distance[next.first] = cost; // 최단 거리 갱신
                pq.emplace(cost, next.first); // 우선순위 큐에 추가
            }
        }
    }

    // K 시간 이하로 배달 가능한 마을 개수 세기
    return count_if(distance.begin(), distance.end(), [K](int d) { return d <= K; });
}

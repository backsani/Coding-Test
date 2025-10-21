#include <bits/stdc++.h>
using namespace std;

struct Cmp {
    // pq에서 true면 "왼쪽이 우선순위 낮음" → min-heap을 만들려면 부등호를 '>'로
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[0] != b[0]) return a[0] > b[0]; // duration 짧은 게 우선
        if (a[1] != b[1]) return a[1] > b[1]; // 요청 시각 빠른 게 우선
        return a[2] > b[2];                   // id 작은 게 우선
    }
};

int solution(vector<vector<int>> jobs) {
    // jobs: [request, duration]
    const int n = (int)jobs.size();

    // (요청시각, 소요시간, id)로 정렬용 배열
    vector<array<int,3>> arr; arr.reserve(n);
    for (int i = 0; i < n; ++i) arr.push_back({jobs[i][0], jobs[i][1], i});
    sort(arr.begin(), arr.end(), [](auto& a, auto& b){
        return a[0] < b[0]; // 요청시각 오름차순
    });

    // 힙에는 (duration, request, id) 형태로 넣음
    priority_queue<vector<int>, vector<vector<int>>, Cmp> pq;

    long long answer = 0;        // 반환시간 합
    long long t = 0;             // currentTime
    int i = 0;                   // arr에서 아직 안 넣은 처음 인덱스
    int done = 0;

    while (done < n) {
        // 현재 시각까지 도착한 모든 작업을 대기열에 투입
        while (i < n && arr[i][0] <= t) {
            pq.push({arr[i][1], arr[i][0], arr[i][2]}); // (dur, req, id)
            ++i;
        }

        if (pq.empty()) {
            // 대기열이 비었으면 시간을 다음 도착 시각으로 점프
            t = max<long long>(t, arr[i][0]);
            continue;
        }

        // 가장 우선순위 높은 작업 처리
        auto job = pq.top(); pq.pop();       // job = {dur, req, id}
        t += job[0];                         // 끝나는 시각
        answer += (t - job[1]);              // 반환시간 = 종료 - 요청
        ++done;
    }

    return (int)(answer / n);
}

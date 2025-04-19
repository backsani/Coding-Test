#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int coverage = 2 * w + 1;
    int left = 1; // 현재 커버되지 않은 시작 지점

    for (int i = 0; i < stations.size(); i++)
    {
        int start = stations[i] - w;
        int end = stations[i] + w;

        // 기지국 커버 영역 앞에 빈 구간이 있다면 처리
        if (left < start)
        {
            int gap = start - left;
            answer += ceil(static_cast<double>(gap) / coverage);
        }

        // 다음 커버되지 않은 시작점 갱신
        left = end + 1;
    }

    // 마지막 기지국 뒤에 빈 구간 처리
    if (left <= n)
    {
        int gap = n - left + 1;
        answer += ceil(static_cast<double>(gap) / coverage);
    }

    return answer;
}

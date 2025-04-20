#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int arr[201] = {0}; // -100 ~ 100 좌표 범위 → 0 ~ 200으로 변환

    for (auto& line : lines) {
        int start = line[0] + 100;
        int end = line[1] + 100;

        for (int i = start; i < end; i++) {
            arr[i]++;
        }
    }

    int answer = 0;
    for (int i = 0; i < 201; i++) {
        if (arr[i] >= 2) // 2개 이상 선분이 겹치는 구간만 세기
            answer++;
    }

    return answer;
}

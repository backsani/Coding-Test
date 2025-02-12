#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void makeCourse(vector<char> v, string course, int target, vector<string>& result) {
    if (course.size() == target) {
        result.push_back(course);
        return;
    }

    for (size_t i = 0; i < v.size(); i++) {
        makeCourse(vector<char>(v.begin() + i + 1, v.end()), course + v[i], target, result);  // 후속 문자만 선택
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int cnt : course) {
        map<string, int> orderCount;
        vector<string> temp;

        // 각 주문에서 해당 크기의 조합을 생성
        for (string order : orders) {
            vector<char> orderChars(order.begin(), order.end());
            sort(orderChars.begin(), orderChars.end());  // 사전 순으로 정렬

            vector<string> combinations;
            makeCourse(orderChars, "", cnt, combinations);  // 해당 크기 조합 찾기

            for (string comb : combinations) {
                orderCount[comb]++;
            }
        }

        // 가장 많이 나온 조합의 개수를 찾기
        int maxCount = 0;
        for (const auto& entry : orderCount) {
            maxCount = max(maxCount, entry.second);
        }

        // maxCount와 일치하는 조합을 결과에 추가
        for (const auto& entry : orderCount) {
            if (entry.second == maxCount && maxCount >= 2) {  // 최소 2명이 주문한 경우만
                answer.push_back(entry.first);
            }
        }
    }

    sort(answer.begin(), answer.end());  // 사전 순으로 정렬
    return answer;
}

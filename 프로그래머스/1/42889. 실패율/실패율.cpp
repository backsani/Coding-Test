#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> challenge(N + 1, 0); 
    vector<int> remain(N + 1, 0); 
    vector<int> answer;           
    vector<pair<int, float>> failure_rate;

    for (int stage : stages) {
        if (stage <= N) {
            remain[stage]++;
        }
        for (int i = 1; i <= min(stage, N); i++) {
            challenge[i]++;
        }
    }


    for (int i = 1; i <= N; i++) {
        if (challenge[i] == 0) {
            failure_rate.push_back({i, 0.0f});
        } else {
            failure_rate.push_back({i, static_cast<float>(remain[i]) / challenge[i]});
        }
    }


    sort(failure_rate.begin(), failure_rate.end(), [](const pair<int, float>& a, const pair<int, float>& b) {
        if (a.second == b.second) {
            return a.first < b.first; 
        }
        return a.second > b.second; 
    });

   
    for (const auto& [stage, rate] : failure_rate) {
        answer.push_back(stage);
    }

    return answer;
}

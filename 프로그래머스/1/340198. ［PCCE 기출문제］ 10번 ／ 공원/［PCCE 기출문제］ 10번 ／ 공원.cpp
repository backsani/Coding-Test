#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    if (park.empty() || park[0].empty()) {
        return 0; // 빈 공원 처리
    }

    int answer = -1;

    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == "-1") {
                int cx = 1;
                int cy = 1;
                bool run = true;
                int cSize = 1;

                while (run && cx + i < park.size() && cy + j < park[0].size()) {
                    for (int ci = i; ci < cx + i + 1 && ci < park.size() && run; ci++) {
                        for (int cj = j; cj < cy + j + 1 && cj < park[0].size() && run; cj++) {
                            if (park[ci][cj] != "-1") {
                                run = false;
                            }
                        }
                    }
                    if (run) {
                        cx++;
                        cy++;
                        cSize++;
                    }
                }

                if (!mats.empty() && find(mats.begin(), mats.end(), cSize) != mats.end()) {
                    answer = max(cSize, answer);
                }
            }
        }
    }

    return answer;
}

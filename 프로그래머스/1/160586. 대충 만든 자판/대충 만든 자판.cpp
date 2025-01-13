#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    int maxSize = 0;

    for (const string& str : keymap) {
        maxSize = max(maxSize, (int)str.size());
    }

    for (int index = 0; index < targets.size(); index++) {
        for (int k = 0; k < targets[index].size(); k++) {
            bool found = false;
            for (int i = 0; i < maxSize && !found; i++) {
                for (int j = 0; j < keymap.size() && !found; j++) {
                    if (i < keymap[j].size() && keymap[j][i] == targets[index][k]) {
                        if (answer[index] == -1) {
                            break;
                        }
                        answer[index] += i + 1;
                        found = true;
                    }
                }
            }
            if (!found) {
                answer[index] = -1;
                break;
            }
        }
    }

    return answer;
}

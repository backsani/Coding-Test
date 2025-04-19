#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> babb = { "aya", "ye", "woo", "ma" };

    for (string str : babbling)
    {
        string prev = "";     // 바로 이전에 제거한 단어
        bool isSpeak = true;

        while (isSpeak)
        {
            isSpeak = false;

            for (int i = 0; i < babb.size(); i++)
            {
                size_t index = str.find(babb[i]);
                if (index == 0 && babb[i] != prev)
                {
                    str.erase(0, babb[i].size());
                    prev = babb[i];
                    isSpeak = true;
                    break;
                }
            }
        }

        if (str.empty()) answer++;
    }

    return answer;
}

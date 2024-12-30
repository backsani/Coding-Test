#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> speak = {"aya", "ye", "woo", "ma"};

    for (string str : babbling) {
        string prev = "";
        bool valid = true;

        while (!str.empty()) {
            bool found = false;

            for (string sp : speak) {
                if (str.find(sp) == 0) {
                    if (prev == sp) { 
                        valid = false;
                        break;
                    }
                    prev = sp; 
                    str.erase(0, sp.size()); 
                    found = true;
                    break;
                }
            }

            if (!found) { 
                valid = false;
                break;
            }
        }

        if (valid) answer++;
    }

    return answer;
}

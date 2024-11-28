#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    unordered_map<string, int> friendsIndex;

    for (int i{}; i < friends.size(); i++) {
        friendsIndex[friends[i]] = i;
    }

    vector<vector<int>> fList(friends.size(), vector<int>(friends.size(), 0));
    vector<int> gValue(friends.size(), 0);
    vector<int> gCopyValue(friends.size(), 0);
    vector<vector<int>> fCopyList(friends.size(), vector<int>(friends.size(), 0));

    for (string& strF : gifts) {
        stringstream ss(strF);
        string toF;
        string fromF;
        ss >> fromF >> toF;

        fList[friendsIndex[fromF]][friendsIndex[toF]]++;
    }

    for (int i = 0; i < fList.size(); i++) {
        int send = 0;
        int recv = 0;
        for (vector<int> n : fList) {
            recv += n[i];
        }
        for (int j = 0; j < fList.size(); j++) {
            send += fList[i][j];
        }

        gValue[i] = send - recv;
    }

    fCopyList = fList;

    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (fList[i][j] > fList[j][i]) {
                fCopyList[j][i]++;
            }
            else if (fList[i][j] < fList[j][i]) {
                fCopyList[i][j]++;
            }
            else if (fList[i][j] == fList[j][i] && gValue[i] != gValue[j]) {
                gValue[i] > gValue[j] ? fCopyList[j][i]++ : fCopyList[i][j]++;
            }

        }
    }

    for (int i = 0; i < fCopyList.size(); i++) {
        int send = 0;
        int recv = 0;
        for (vector<int> n : fCopyList) {
            recv += n[i];
        }
        for (int j = 0; j < fCopyList.size(); j++) {
            send += fCopyList[i][j];
        }

        gCopyValue[i] = send - recv;
    }

    int max = 0;

    for (int i = 0; i < fList.size(); i++) {
        int recv = 0;
        for (vector<int> n : fList) {
            recv += n[i];
        }
        int copyRecv = 0;
        for (vector<int> n : fCopyList) {
            copyRecv += n[i];
        }

        max = max < copyRecv - recv ? copyRecv - recv : max;
    }


    return max;
}
#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(int n, vector<int> works) {
    long long total = 0;
    map<int, int> work;  // (작업량 -> 개수)

    // 초기화
    for (int x : works) {
        work[x]++;
        total += x;
    }

    // 전체 합이 n보다 작거나 같으면 0
    if (total <= n) return 0;

    while (n > 0) {
        auto it = work.rbegin();            // 현재 최대 작업량
        auto nxit = next(work.rbegin());    // 두 번째로 큰 작업량

        int curr = it->first;
        int cnt = it->second;
        int nextVal = (nxit != work.rend()) ? nxit->first : 0;
        int gap = curr - nextVal;           // 다음 블록까지 내릴 수 있는 폭
        long long need = 1LL * gap * cnt;   // 그만큼 내리는데 필요한 시간

        if (n >= need) {
            // 블록 전체를 다음 블록까지 내림
            n -= need;
            work[nextVal] += cnt;
            work.erase(curr);
        } else {
            // 균등 분배
            int take = n / cnt;   // 모두에게 이만큼 줄임
            int rem  = n % cnt;   // rem개는 한 칸 더

            int newVal = curr - take;
            if (take > 0) {
                work[newVal] += cnt;
                work.erase(curr);
            }
            if (rem > 0) {
                work[newVal] -= rem;
                work[newVal - 1] += rem;
                if (work[newVal] == 0) work.erase(newVal);
            }
            n = 0; // 다 썼으니 종료
        }
    }

    // 최종 피로도 계산
    long long answer = 0;
    for (auto &p : work) 
    {
        answer += 1LL * p.first * p.first * p.second;
    }
    return answer;
}

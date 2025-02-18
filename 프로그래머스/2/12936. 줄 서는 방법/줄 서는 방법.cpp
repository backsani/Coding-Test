#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;   // 사용할 숫자 리스트 (1~n)
    long long fact = 1; // (n-1)! 값을 저장할 변수
    
    // 1부터 n까지 숫자 저장 & 팩토리얼 계산
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact *= i;
    }
    
    k--; // 0-based index로 변경
    
    for (int i = n; i >= 1; i--) {
        fact /= i; // (i-1)! 계산
        int idx = k / fact; // 현재 위치의 숫자 찾기
        answer.push_back(nums[idx]); // 해당 숫자 선택
        nums.erase(nums.begin() + idx); // 선택한 숫자는 제거
        k %= fact; // 다음 자리 선택을 위해 k 업데이트
    }
    
    return answer;
}

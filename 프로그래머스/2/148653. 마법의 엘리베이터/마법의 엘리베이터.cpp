#include <iostream>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int lastDigit = storey % 10; // 마지막 자리수
        int nextDigit = (storey / 10) % 10; // 다음 자리수

        if (lastDigit > 5 || (lastDigit == 5 && nextDigit >= 5)) {
            // 올림 처리
            storey += 10 - lastDigit; 
        } else {
            // 내림 처리
            storey -= lastDigit; 
        }

        // 자리수 이동
        storey /= 10;
        // 버튼 클릭 횟수 추가
        answer += min(lastDigit, 10 - lastDigit);
    }

    return answer;
}

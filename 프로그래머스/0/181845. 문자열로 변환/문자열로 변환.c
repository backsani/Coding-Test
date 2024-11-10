#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int length = 0;
    int a = n;
    
    while(a > 0){
        a/=10;
        length++;
    }
    char* answer = (char*)malloc(length + 1);
    a = n;
    
    for(int i = 0; i < length; i++){
        char b = (a % 10) + '0';
        answer[length - i - 1] = b;
        a /= 10;
    }
    answer[length] = '\0';
    return answer;
}
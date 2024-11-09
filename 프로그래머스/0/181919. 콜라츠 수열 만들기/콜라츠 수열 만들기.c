#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int result = n;
    int length = 1;
    int* answer = (int*)malloc(5 * sizeof(int));
    answer[0] = n;
    
    while(result != 1){
        if(result % 2 == 0){
            result /= 2;
        }
        else{
            result = 3 * result + 1;
        }
        answer[length] = result;
        length++;
        if(length % 4 == 0){
            answer = (int*)realloc(answer, (length * sizeof(int) * 2) + 1);
        }
    }
    
    answer[length] = '\0';
    
    return answer;
}
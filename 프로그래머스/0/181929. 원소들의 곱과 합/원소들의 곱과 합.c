#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int a = 1;
    int b = 0;
    
    for(int i = 0; i < num_list_len; i++){
        a *= num_list[i];
    }
    
    for(int i = 0; i < num_list_len; i++){
        b += num_list[i];
    }
    b = b*b;
    
    answer = a > b ? 0 : 1;
    
    return answer;
}
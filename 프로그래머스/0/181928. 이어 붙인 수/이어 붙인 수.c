#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    
    int a = 1;
    int resultA = 0;
    
    int b = 1;
    int resultB = 0;
    
    for(int i = 0; i < num_list_len; i++){
        if(num_list[i] % 2 == 0){
            resultA *= 10;
            resultA += num_list[i];
            
        }
        else{
            resultB *= 10;
            resultB += num_list[i];
        }
    }
    
    return resultA + resultB;
}
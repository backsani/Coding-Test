#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* stk = (int*)malloc(arr_len * sizeof(int));
    memset(stk, 0,(arr_len * sizeof(int)));
    int i = 0;
    int j = 0;
    
    while(arr[i] != '\0'){
        if(stk[0] == 0 || stk[0] == '\0'){
            stk[j] = arr[i];

        }
        else if(stk[j - 1] < arr[i]){
            stk[j] = arr[i];

        }
        else if(stk[j - 1] >= arr[i]){
            stk[j - 1] = 0;
            j--;
            continue;
        }
        i++;
        j++;
    }
    
    stk[j] = '\0';
    
    return stk;
}
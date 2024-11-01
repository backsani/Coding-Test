#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* str1, const char* str2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int Length = strlen(str1) + strlen(str2) + 1;
    int i = 0;
    int currentLength = 0;
    int finish1 = 0;
    int finish2 = 0;
    char* answer = (char*)malloc(Length);
    
    while(1){
        if(finish1 == 0){
            answer[i] = str1[currentLength];
            i++;
        }
        if(finish2 == 0){
            answer[i] = str2[currentLength];
            i++;
        }
                    
        if(finish1 != 0 && finish2 != 0)
        {
            answer[i] = '\0';
            break;
        }
        
        currentLength++;

        if(str1[currentLength] == '\0' && finish1 == 0){
            finish1++;
        }
        if(str2[currentLength] == '\0' && finish2 == 0){
            finish2++;
        }
    }
    return answer;
}
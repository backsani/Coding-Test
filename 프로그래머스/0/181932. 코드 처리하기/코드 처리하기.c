#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* code) {
    int length = strlen(code);
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(length + 1);
    int mode = 0;
    int answerSize = 0;
    
    for(int i = 0; i < length; i++)
    {
        if(code[i] == '1')
        {
            mode = 1 - mode;
            continue;
        }
        if(mode == 0){
            if(i % 2 == 0){
                answer[answerSize] = code[i];
                answerSize++;
            }
                
        }
        else if(mode == 1){
            if(i % 2 == 1){
                answer[answerSize] = code[i];
                answerSize++;
            }
        }
            
    }
    if(answerSize == 0)
    {
        strcpy(answer, "EMPTY");
        return answer;
    }
        
    answer[answerSize] = '\0';
    
    
    return answer;
}
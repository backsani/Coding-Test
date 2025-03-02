#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열의 괄호 방향을 뒤집는 함수
string changeStr(string str)
{
    str.erase(str.begin());        // 첫 번째 문자 제거
    str.erase(str.end() - 1);    // 마지막 문자 제거

    // 문자열의 각 문자에 대해 괄호 방향 뒤집기
    for(char& ch : str)
    {
        if(ch == '(')
            ch = ')';  // '('를 ')'로 변경
        else
            ch = '(';  // ')'를 '('로 변경
    }

    return str;  // 변경된 문자열 반환
}

// 문자열이 올바른 괄호 문자열인지 확인하는 함수
bool currectStr(string str)
{
    int countLeft = 0;  // 왼쪽 괄호 개수
    int countRight = 0; // 오른쪽 괄호 개수

    // 문자열의 각 문자에 대해
    for(char ch : str)
    {
        if(ch == '(')
            countLeft++;  // 왼쪽 괄호 개수 증가
        else
        {
            countRight++;  // 오른쪽 괄호 개수 증가
            // 오른쪽 괄호가 왼쪽 괄호보다 많으면 올바르지 않은 문자열
            if(countRight > countLeft)
                return false;
        }
    }
    return true;  // 올바른 괄호 문자열이면 true 반환
}

// 재귀적으로 괄호 문자열을 변환하는 함수
string dfs(string v)
{
    // 빈 문자열이면 빈 문자열 반환
    if(v.empty())
        return "";

    string result;  // 결과 문자열

    int countLeft = 0;  // 왼쪽 괄호 개수
    int countRight = 0; // 오른쪽 괄호 개수

    string str1;  // u 문자열
    string str2;  // v 문자열

    // 문자열 v의 각 문자에 대해
    for(char ch : v)
    {
        if(ch == '(')
            countLeft++;  // 왼쪽 괄호 개수 증가
        else if(ch == ')')
            countRight++; // 오른쪽 괄호 개수 증가

        // 균형잡힌 괄호 문자열 u를 찾으면
        if(countLeft != 0 && countLeft == countRight)
        {
            str1 = string(v.begin(), v.begin() + countLeft + countRight);  // u 문자열 추출
            str2 = string(v.begin() + countLeft + countRight, v.end());  // v 문자열 추출
            break;  // 반복문 종료
        }
    }

    bool currect = currectStr(str1);  // u 문자열이 올바른 괄호 문자열인지 확인
    // u 문자열이 올바른 괄호 문자열이면
    if(currect)
    {
        result = str1 + dfs(str2);  // u + dfs(v)
    }
    // u 문자열이 올바른 괄호 문자열이 아니면
    else
    {
        result = "(" + dfs(str2) + ")" + changeStr(str1);  // ( + dfs(v) + ) + changeStr(u)
    }

    return result;  // 결과 문자열 반환
}

// 주어진 문자열 p를 올바른 괄호 문자열로 변환하는 함수
string solution(string p) {
    return dfs(p);;  // dfs 함수 호출
}

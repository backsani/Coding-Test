#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

string calculate(string num1, string op, string num2)
{
    if (op == "+")
        return to_string(stoll(num1) + stoll(num2));
    else if (op == "-")
        return to_string(stoll(num1) - stoll(num2));
    else if (op == "*")
        return to_string(stoll(num1) * stoll(num2));

    return "";
}

string calOperate(vector<string>& v, int op)
{
    string operate;
    
    if (op == 1)
        operate = "+";
    else if (op == 2)
        operate = "-";
    else if (op == 3)
        operate = "*";
    
    for(int i = 1; i < v.size(); i+=2)
    {
        if(v[i] == operate)
        {
            v[i-1] = calculate(v[i-1], v[i], v[i+1]);
            v.erase(v.begin() + i, v.begin() + i + 2);
            i -= 2;
        }
    }

    return "";
}

long long bfs(vector<string> v)
{
    long long max = 0;
    
    queue<pair<vector<string>, vector<int>>> q;
    q.push(make_pair(v, vector<int>()));
    
    while(!q.empty())
    {
        pair<vector<string>, vector<int>> tempA = q.front();
        q.pop();
        
        for(int i = 1; i <= 3; i++)
        {
            pair<vector<string>, vector<int>> temp = tempA;
            if(find(temp.second.begin(), temp.second.end(), i) != temp.second.end())
                continue;
            
            calOperate(temp.first, i);
            
            if(temp.first.size() == 1)
            {
                long long num = stoll(temp.first[0]);
                if(num < 0)
                    num = num * -1;
                max = num > max ? num : max;
            }
            
            temp.second.push_back(i);
            
            q.push(temp);
        }
    }

    return max;
}

long long solution(string expression) {
    vector<string> v;
    string temp;

    // 표현식을 숫자와 연산자로 분리
    for (char ch : expression)
    {
        if (isdigit(ch))
        {
            temp += ch;  // 숫자가 계속 나오면 temp에 쌓음
        }
        else
        {
            if (!temp.empty()) {
                v.push_back(temp);  // 이전 숫자가 있으면 벡터에 추가
                temp = "";  // 숫자 처리 후 temp 초기화
            }
            v.push_back(string(1, ch));  // 연산자는 한 문자씩 추가
        }
    }
    if (!temp.empty()) {
        v.push_back(temp);  // 마지막 숫자도 벡터에 추가
    }

    return bfs(v);  // bfs 함수 호출하여 최대값 반환
}

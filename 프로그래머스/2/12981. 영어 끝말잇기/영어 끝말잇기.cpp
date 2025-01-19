#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    answer[1] = 1;
    
    int tun = 0;
    vector<string> v;
    char lastWord = words[0][0];
    
    for(string str : words)
    {
   
        auto it = find(v.begin(), v.end(), str);
        
        if((it != v.end() || str[0] != lastWord))
        {
            answer[0] = tun + 1;
            return answer;
        }
        else if(it == v.end())
        {
            v.push_back(str);     
        }
        
        tun++;
        if(tun == n)
        {
            answer[1] += 1;
            tun = 0;
        }
        
        lastWord = str.back();
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "Hello Cpp" << endl;

    return {0,0};
}
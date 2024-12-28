#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> n) {
    vector<int> nums = n;
    int answer = 0;
    int debug = 0;
    vector<int> number;

    vector<bool> select(nums.size(), false);
    fill(select.begin(), select.begin() + 3, true);
    
    do
    {
        int temp = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(select[i])
                temp += nums[i];
        }
        number.push_back(temp);
    }while(prev_permutation(select.begin(), select.end()));

    sort(number.begin(), number.end());
    
    vector<bool> prime(number.back(), true);
    cout << number.back() << endl;
    
    prime[0] = false;
    for(int i = 2; i * i <= prime.size(); i++)
    {
        int j = 2;
        while(i * j <= prime.size())
        {
            prime[i*j - 1] = false;
            j++;
        }
    }
    
    for(int num : number)
    {
        if(prime[num - 1] == true)
        {
            
            answer++;
        }
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    

    return answer;
}
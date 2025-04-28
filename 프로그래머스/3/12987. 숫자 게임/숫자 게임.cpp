#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    int count = 0;
    
    int frontPoint = 0;
    int backPoint = A.size() - 1;
    
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < A.size(); i++)
    {
        if(B[i] > A[backPoint])
        {
            backPoint--;
            count++;
        }

        else
            frontPoint++;
    }
    
    return count;
}
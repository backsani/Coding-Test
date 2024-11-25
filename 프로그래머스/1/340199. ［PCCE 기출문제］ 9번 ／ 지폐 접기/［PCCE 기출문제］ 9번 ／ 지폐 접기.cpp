#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int billIndex = 0;
    
    while(1){
        if((wallet[0] >= bill[0] && wallet[1] >= bill[1]) || (wallet[0] >= bill[1] && wallet[1] >= bill[0])){
            break;
        }
        billIndex = bill[0] > bill[1] ? 0 : 1;
        bill[billIndex] /= 2;
        answer++;
    }
    
    return answer;
}
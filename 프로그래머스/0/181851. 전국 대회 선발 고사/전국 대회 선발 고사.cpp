#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    int one, two, three;
    one = two = three = 101;
    
    
    for(int i = 0; i < rank.size(); i++){
        if(attendance[i] == true){
            if(rank[i] < rank[one] || one == 101){
                three = two;
                two = one;
                one = i;
            }
            else if(rank[i] < rank[two] || two == 101){
                three = two;
                two = i;
            }
            else if(rank[i] < rank[three] || three == 101){
                three = i;
            }
        }
    }
    
    return one * 10000 + two * 100 + three;
}
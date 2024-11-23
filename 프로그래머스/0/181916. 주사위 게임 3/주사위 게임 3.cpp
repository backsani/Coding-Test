#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> SameCountFun(int a, int b, int c, int d){
    vector<int> sameCount;
    
    if(a == b && b == c && c == d && d == a){
        sameCount.push_back(4);
        
        return sameCount;
    }
    else if((a == b && b == c) || (b == c && c == d) || (c == d && d == a) || (a == b && b == d)){
        sameCount.push_back(3);
        if(a == b && b == c)
            sameCount.push_back(d);
        else if(a == b && b == d)
            sameCount.push_back(c);
        else if(d == b && b == c)
            sameCount.push_back(a);
        else if(a == c && d == c)
            sameCount.push_back(b);
        sameCount.push_back(sameCount[1] == a ? b : a);
    }
    else if((a == b && c == d && a != c) || (a == c && b == d && a != b) || (a == d && b == c && a != b)){
        sameCount.push_back(2);
        sameCount.push_back(1);
        if(a == b){
            sameCount.push_back(a);
            sameCount.push_back(c);
        }
        else if(a == c){
            sameCount.push_back(a);
            sameCount.push_back(b);
        }
        else if(a == d){
            sameCount.push_back(a);
            sameCount.push_back(c);
        }
    }
    else if((a == b && c != d) || (a == c && b != d) || (a == d && b != c) || (b == c && a != d) || (b == d && a != c) || (c == d && a != b)){
        sameCount.push_back(2);
        sameCount.push_back(0);
        if(a == b){
            sameCount.push_back(d);
            sameCount.push_back(c);
        }
        else if(a == c){
            sameCount.push_back(d);
            sameCount.push_back(b);
        }
        else if(a == d){
            sameCount.push_back(b);
            sameCount.push_back(c);
        }
        else if(c == b){
            sameCount.push_back(d);
            sameCount.push_back(a);
        }
        else if(d == b){
            sameCount.push_back(a);
            sameCount.push_back(c);
        }
        else if(d == c){
            sameCount.push_back(a);
            sameCount.push_back(b);
        }
    }
    else if(a != b && b != c && c != d && a != c && a != d && b != d){
        sameCount.push_back(1);
        sameCount.push_back(a);
        sameCount.push_back(b);
        sameCount.push_back(c);
        sameCount.push_back(d);
    }
    
    return sameCount;
}


int solution(int a, int b, int c, int d) {
    int answer = 0;
    vector<int> sameCount = SameCountFun(a,b,c,d);
    
    if(sameCount[0] == 4){
        answer = a * 1111;
    }
    else if(sameCount[0] == 3){
        answer = pow(sameCount[2] * 10 + sameCount[1], 2);
    }
    else if(sameCount[0] == 2){
        if(sameCount[1] == true){
            answer = (sameCount[2] + sameCount[3]) * abs(sameCount[2] - sameCount[3]);
        }
        else if(sameCount[1] == false){
            answer = sameCount[2] * sameCount[3];
        }
    }
    else if(sameCount[0] == 1){
        sameCount.erase(sameCount.begin());
        answer = *min_element(sameCount.begin(), sameCount.end());
    }
    
    return answer;
}
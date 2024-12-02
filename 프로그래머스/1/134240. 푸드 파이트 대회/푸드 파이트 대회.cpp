#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    food.erase(food.begin());
    
    int foodId = 0;
    for(int num : food)
    {
        foodId++;
        for(int i = 0; i < num/2; i++){
            answer += to_string(foodId);
        }
    }
    
    string ranswer = answer;
    reverse(ranswer.begin(), ranswer.end());
    answer = answer + "0" + ranswer; 
    
    return answer;
}
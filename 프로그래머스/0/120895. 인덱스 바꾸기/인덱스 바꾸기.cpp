#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string temp = my_string;
    char c1 = my_string[num1];
    temp[num1] = temp[num2];
    temp[num2] = c1;
    return temp;
}
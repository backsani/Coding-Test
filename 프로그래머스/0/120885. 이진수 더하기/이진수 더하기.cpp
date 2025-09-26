#include <string>
#include <vector>

using namespace std;

string itob(int i)
{
    string result = "";
    if(i == 0)
        return "0";
    
    while(i > 0)
    {
        result = to_string(i % 2) + result;
        i /= 2;
    }
    
    
    return result;
}

int btoi(string b)
{
    int result = 0;
    int i = 1;
    while(!b.empty())
    {
        result += stoi(b.substr(b.size() - 1, 1)) * i;
        if(b.size() - 1 == 0)
            break;
        b = b.substr(0, b.size() - 1);
        i *= 2;
    }
    return result;
}

string solution(string bin1, string bin2) {
    return itob(btoi(bin1) + btoi(bin2));
}
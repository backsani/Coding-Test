#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(string letter) {
    string answer = "";
    map<string, char> m = {
        {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'},
        {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'},
        {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'}, {"-.", 'n'}, {"---", 'o'},
        {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
        {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'},
        {"--..", 'z'}
    };
    
    stringstream ss(letter);
    
    string temp;
    while(getline(ss, temp, ' '))
    {
        answer += m[temp];
    }
    
    
    return answer;
}
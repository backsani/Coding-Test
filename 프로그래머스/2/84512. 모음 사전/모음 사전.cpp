#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, char> m;

int dictionary(int index, string currentWord, string target)
{
    if(currentWord == target)
        return index;
    
    if(currentWord.size() < 5)
    {
        currentWord += "A";
    }
    else
    {
        int i = 4;
        while(true)
        {
            if(currentWord[i] == 'U')
            {
                currentWord = currentWord.substr(0, i);
                i--;
                continue;
            }
            else
            {
                currentWord[i] = m[currentWord[i]];
                break;
            }
        }
    }
    
    return dictionary(index + 1, currentWord, target);
}

int solution(string word) {
    int index = 0;
    
    m['A'] = 'E'; m['E'] = 'I'; m['I'] = 'O'; m['O'] = 'U'; 
    
    return dictionary(index + 1, "A", word);;
}
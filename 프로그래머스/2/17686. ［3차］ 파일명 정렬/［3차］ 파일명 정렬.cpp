#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string toLower(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> v;

    for (string file : files) {
        string header = "", number = "", tail = "";
        
        int idx = 0;
        int len = file.size();

        while (idx < len && !isdigit(file[idx])) 
        {
            header += file[idx++];
        }

        while (idx < len && isdigit(file[idx]) && number.size() < 5) 
        {
            number += file[idx++];
        }

        tail = file.substr(idx);

        v.push_back({header, number, tail});
    }

    stable_sort(v.begin(), v.end(), [](const vector<string>& a, const vector<string>& b) {
        if (toLower(a[0]) == toLower(b[0]))
            return stoi(a[1]) < stoi(b[1]);
        return toLower(a[0]) < toLower(b[0]);
    });

    for (vector<string> str : v) 
    {
        answer.push_back(str[0] + str[1] + str[2]);
    }

    return answer;
}

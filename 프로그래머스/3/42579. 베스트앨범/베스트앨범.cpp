#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    // index, plays
    map<string, vector<pair<int, int>>> genreM;
    
    for(int i = 0; i < genres.size(); i++)
    {
        m[genres[i]] += plays[i];
        genreM[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b){
             return a.second > b.second;
         });
    
    for(pair<string, int> p : v)
    {
        vector<pair<int, int>> genre = genreM[p.first];
        
        if(genre.size() == 1)
        {
            answer.push_back(genre[0].first);
            continue;
        }
        
        sort(genre.begin(), genre.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        
        answer.push_back(genre[0].first);
        answer.push_back(genre[1].first);
    }
    
    return answer;
}
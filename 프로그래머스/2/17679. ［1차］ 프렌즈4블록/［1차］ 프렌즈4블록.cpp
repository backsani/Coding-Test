#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool hit(vector<vector<pair<char, bool>>>& v, int i, int j, int& count)
{
    bool check = false;
    if(j + 1 < v[0].size() && i + 1 < v.size())
    {
        if(v[i][j].first != ' ' && v[i][j].first == v[i][j + 1].first && v[i][j].first == v[i + 1][j].first && v[i][j].first == v[i + 1][j + 1].first)
        {
            if(v[i][j].second == true)
                count++;
            if(v[i][j + 1].second == true)
                count++;
            if(v[i + 1][j].second == true)
                count++;
            if(v[i + 1][j + 1].second == true)
                count++;
                
            v[i][j].second = false;
            v[i][j + 1].second = false;
            v[i + 1][j].second = false;
            v[i + 1][j + 1].second = false;
            
            check = true;
        }
    }
    
    return check;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<pair<char, bool>>> v(m, vector<pair<char, bool>>(n, make_pair('B', true))); 
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            v[i][j] = make_pair(board[i][j], true);
        }
    }
        
    
    bool run = true;
    while(run)
    {
        run = false;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool b = hit(v, i, j, answer);
                if(!run)
                    run = b;
            }
        }
        
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(v[i][j].second == false)
                {
                    v[i][j] = {' ', false};
                    
                    for(int h = i - 1; h >= 0; h--)
                    {
                        if(v[h][j].second != false)
                        {
                            v[i][j] = v[h][j];
                            v[h][j] = {' ', false};
                            break;
                        }
                        
                    }
                    
                }
            }
        }
    }
    
    
    
    return answer;
}
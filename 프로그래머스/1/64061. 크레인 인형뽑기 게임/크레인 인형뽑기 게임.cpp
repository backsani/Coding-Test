#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> result;
    
    for(int pick : moves)
    {
        bool run = true;
        int i = 0;
        while(run)
        {
            run = false;
            
            if(board[i][pick-1] == 0)
            {
                i++;
                if(i == board.size())
                    break;
                run = true;
            }
            else
            {
                result.push_back(board[i][pick-1]);
                board[i][pick-1] = 0;
                while(result.size() >= 2 && result[result.size() - 1] == result[result.size() - 2])
                {
                    result.pop_back();
                    result.pop_back();
                    answer += 2;
                }
            }
        }
        
    }
    
    return answer;
}
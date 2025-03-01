#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    if (board.empty()) return 0;
    
    if(board.size() == 1 && board[0].size() == 1)
        return 1;

    int rows = board.size();
    int cols = board[0].size();
    int max_side = 0;

    // DP 테이블을 board 자체를 사용하여 공간 최적화
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (board[i][j] == 1) {
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
                max_side = max(max_side, board[i][j]);
            }
        }
    }

    // 가장 큰 정사각형의 넓이 반환
    return max_side * max_side;
}

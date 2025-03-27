#include <string>
#include <vector>

using namespace std;

// 승리 확인 함수
bool checkWin(const vector<string>& board, char player) {
    // 가로, 세로, 대각선 확인
    for (int i = 0; i < 3; i++) {
        // 가로
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        // 세로
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // 대각선
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

int solution(vector<string> board) {
    int Ocount = 0, Xcount = 0;
    
    // O와 X의 개수 세기
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') Ocount++;
            else if (board[i][j] == 'X') Xcount++;
        }
    }
    
    // 규칙 1: O의 개수는 X의 개수보다 많거나 같고, X의 개수는 O의 개수보다 1 많을 수 없다.
    if (!(Ocount == Xcount || Ocount == Xcount + 1))
        return 0;
    
    // O와 X 각각의 승리 확인
    bool Owin = checkWin(board, 'O');
    bool Xwin = checkWin(board, 'X');
    
    // 규칙 2: O와 X가 동시에 이길 수 없음
    if (Owin && Xwin) return 0;
    
    // 규칙 3: O가 이겼다면 O의 개수는 X보다 정확히 1개 많아야 하고, X가 이겼다면 O의 개수는 X와 같아야 한다.
    if ((Owin && Ocount != Xcount + 1) || (Xwin && Ocount != Xcount))
        return 0;
    
    // 모든 규칙을 통과하면 게임 상태는 유효
    return 1;
}

#include <vector>
#include <iostream>
#define EMPTY '0'
#define P_1 '1'
#define P_2 '2'
#define P_1_WON "FIRST_PLAYER_WINS"
#define P_2_WON "SECOND_PLAYER_WINS"
#define TIE "BOTH_PLAYERS_TIE"
using namespace std;
bool isMovesLeft(const int width, const int height, char** board) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == EMPTY) {
                return true;
            }
        }
    }
    return false;
}
int hasAnybodyWon(const int width, const int height, const int to_win, char** board) {
    int p1_count = 0;
    int p2_count = 0;
    //check if player wins in rows
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (board[row][col] == EMPTY) {
                p1_count = 0;
                p2_count = 0;
            }
            else if (board[row][col] == P_1) {
                p1_count++;
                p2_count = 0;
            }
            else if (board[row][col] == P_2) {
                p2_count++;
                p1_count = 0;
            }
            if (p1_count == to_win) {
                return 1;
            }
            else if (p2_count == to_win) {
                return -1;
            }
        }
        p1_count = 0;
        p2_count = 0;
    }
    //check if player wins in collumns
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            if (board[row][col] == EMPTY) {
                p1_count = 0;
                p2_count = 0;
            }
            else if (board[row][col] == P_1) {
                p1_count++;
                p2_count = 0;
            }
            else if (board[row][col] == P_2) {
                p2_count++;
                p1_count = 0;
            }
            if (p1_count == to_win) {
                return 1;
            }
            else if (p2_count == to_win) {
                return -1;
            }
        }
        p1_count = 0;
        p2_count = 0;
    }
    //check main diagonal
    for (int row = 0; row < height - to_win + 1; row++) {
        for (int col = 0; col < width - to_win + 1; col++) {
            for (int i = 0; i < to_win; i++) {
                if (board[row + i][col + i] == EMPTY) {
                    p1_count = 0;
                    p2_count = 0;
                }
                else if (board[row + i][col + i] == P_1) {
                    p1_count++;
                    p2_count = 0;
                }
                else if (board[row + i][col + i] == P_2) {
                    p2_count++;
                    p1_count = 0;
                }

                if (p1_count == to_win) {
                    return 1;
                }
                else if (p2_count == to_win) {
                    return -1;
                }
            }
            p1_count = 0;
            p2_count = 0;
        }
    }
    //check cross diagonal
    for (int row = 0; row < height - to_win + 1; row++) {
        for (int col = to_win - 1; col < width; col++) {
            for (int i = 0; i < to_win; i++) {
                if (board[row + i][col - i] == EMPTY) {
                    p1_count = 0;
                    p2_count = 0;
                }
                else if (board[row + i][col - i] == P_1) {
                    p1_count++;
                    p2_count = 0;
                }
                else if (board[row + i][col - i] == P_2) {
                    p2_count++;
                    p1_count = 0;
                }

                if (p1_count == to_win) {
                    return 1;
                }
                else if (p2_count == to_win) {
                    return -1;
                }
            }
            p1_count = 0;
            p2_count = 0;
        }
    }
    return 0;
}
int evaluateNextMove(const int width, const int height, const int to_win, char** board, int x_pos, int y_pos) {
    int p1_count = 0;
    int p2_count = 0;
    //check if player wins in rows
    int row = y_pos;
    for (int col = 0; col < width; col++) {
        if (board[row][col] == EMPTY) {
            p1_count = 0;
            p2_count = 0;
        }
        else if (board[row][col] == P_1) {
            p1_count++;
            p2_count = 0;
        }
        else if (board[row][col] == P_2) {
            p2_count++;
            p1_count = 0;
        }
        if (p1_count == to_win) {
            return 1;
        }
        else if (p2_count == to_win) {
            return -1;
        }
    }
    p1_count = 0;
    p2_count = 0;
    for (int row = 0; row < height; row++) {
        int col = x_pos;
        if (board[row][col] == EMPTY) {
            p1_count = 0;
            p2_count = 0;
        }
        else if (board[row][col] == P_1) {
            p1_count++;
            p2_count = 0;
        }
        else if (board[row][col] == P_2) {
            p2_count++;
            p1_count = 0;
        }
        if (p1_count == to_win) {
            return 1;
        }
        else if (p2_count == to_win) {
            return -1;
        }
    }
    p1_count = 0;
    p2_count = 0;
    //check main diagonal
    for (int row = 0; row < height - to_win + 1; row++) {
        for (int col = 0; col < width - to_win + 1; col++) {
            for (int i = 0; i < to_win; i++) {
                if (board[row + i][col + i] == EMPTY) {
                    p1_count = 0;
                    p2_count = 0;
                }
                else if (board[row + i][col + i] == P_1) {
                    p1_count++;
                    p2_count = 0;
                }
                else if (board[row + i][col + i] == P_2) {
                    p2_count++;
                    p1_count = 0;
                }

                if (p1_count == to_win) {
                    return 1;
                }
                else if (p2_count == to_win) {
                    return -1;
                }
            }
            p1_count = 0;
            p2_count = 0;
        }
    }
    //check cross diagonal
    for (int row = 0; row < height - to_win + 1; row++) {
        for (int col = to_win - 1; col < width; col++) {
            for (int i = 0; i < to_win; i++) {
                if (board[row + i][col - i] == EMPTY) {
                    p1_count = 0;
                    p2_count = 0;
                }
                else if (board[row + i][col - i] == P_1) {
                    p1_count++;
                    p2_count = 0;
                }
                else if (board[row + i][col - i] == P_2) {
                    p2_count++;
                    p1_count = 0;
                }

                if (p1_count == to_win) {
                    return 1;
                }
                else if (p2_count == to_win) {
                    return -1;
                }
            }
            p1_count = 0;
            p2_count = 0;
        }
    }
    return 0;
}

void printBoard(const int width, const int height, char** board) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void putInputBoard(const int width, const int height, char** board) {
    char board_input;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board_input;
            board[i][j] = board_input;
        }
    }
}
int minFunction(int a, int b) {
    if (a > b) {
        return b;
    }
    else
        return a;
}
int maxFunction(int a, int b) {
    if (a >= b) {
        return a;
    }
    else
        return b;
}
int minMax(const int width, const int height, const int to_win, char** board, bool isMax,int depth,int alpha,int beta) {
    int score = hasAnybodyWon(width, height, to_win, board);
    if (score == 1) {
        return score;
    }
    if (score == -1) {
        return score;
    }
    if (isMovesLeft(width, height, board) == false) {
        return 0;
    }
    if (isMax) {
        int best = -100000;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = P_1;
                    score = minMax(width, height, to_win, board, false,depth+1,alpha,beta);
                    board[i][j] = EMPTY;
                    if (score > best) {
                        best = score;
                    }
                    if (score > alpha) {
                        alpha = score;
                    }
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best;
    }
    else
    {
        int best = 100000;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = P_2;
                    score = minMax(width, height, to_win, board, true, depth + 1, alpha, beta);
                    board[i][j] = EMPTY;
                    if (score < best) {
                        best = score;
                    }
                    if (score < beta) {
                        beta = score;
                    }
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return best;
    }
}
void allPossibleSolution(int width, int height, int moveCount, char** tab, char whoesTurn) {
    cout << moveCount << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[i][j] == EMPTY) {
                tab[i][j] = whoesTurn;
                printBoard(width, height, tab);
                tab[i][j] = EMPTY;
            }
        }
    }
}

void allPossibleSolution(int width, int height, char** tab, int to_win, char whoesTurn) {
    int moveCount = 0;
    if (hasAnybodyWon(width, height, to_win, tab) != 0) {
        cout << "0" << endl;
        return;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[i][j] == EMPTY) {
                moveCount++;
            }
        }
    }
    cout << moveCount << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[i][j] == EMPTY) {
                tab[i][j] = whoesTurn;
                printBoard(width, height, tab);
                tab[i][j] = EMPTY;
            }
        }
    }
}
void allPossibleSolutionCutIfGameOver(int width, int height, int to_win, char** tab, char whoesTurn) {
    int whoWon;
    int moveCount = 0;
    bool is_game_cut = false;
    whoWon = hasAnybodyWon(width, height, to_win, tab);
    if (whoWon != 0) {
        cout << "0" << endl;
        return;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tab[i][j] == EMPTY) {
                tab[i][j] = whoesTurn;
                moveCount++;
                whoWon = evaluateNextMove(width, height, to_win, tab, j, i);
                if (whoWon == 0) {
                    if (!isMovesLeft(width, height, tab)) {
                        is_game_cut = true;
                        break;
                    }
                }
                else if (whoWon == 1) {
                    is_game_cut = true;
                    break;
                }
                else if (whoWon == -1) {
                    is_game_cut = true;
                    break;
                }
                tab[i][j] = EMPTY;
            }
        }
        if (is_game_cut) {
            break;
        }
    }
    if (moveCount == 0) {
        cout << "0" << endl;
        return;
    }
    if (is_game_cut) {
        cout << "1" << endl;
        printBoard(width, height, tab);
        return;
    }
    else {
        allPossibleSolution(width, height, moveCount, tab, whoesTurn);
        return;
    }
}

int main() {
    char function_name[40];
    int width, height, to_win;
    char active_player;
    while (1) {
        cin >> function_name;
        if (feof(stdin) != 0)
        {
            break;
        }
        if (std::strcmp(function_name, "GEN_ALL_POS_MOV") == 0) {
            cin >> height; cin >> width; cin >> to_win; cin >> active_player;
            char** board = new char* [height];
            for (int i = 0; i < height; i++) {
                board[i] = new char[width];
            }
            putInputBoard(width, height, board);
            allPossibleSolution(width, height, board, to_win, active_player);
            //genAllPosMoves();
        }
        else if (std::strcmp(function_name, "GEN_ALL_POS_MOV_CUT_IF_GAME_OVER") == 0) {
            cin >> height; cin >> width; cin >> to_win; cin >> active_player;
            char** board = new char* [height];
            for (int i = 0; i < height; i++) {
                board[i] = new char[width];
            }
            putInputBoard(width, height, board);
            allPossibleSolutionCutIfGameOver(width, height, to_win, board, active_player);
            //genAllPosMoveCutIfGameOver();
        }
        else if (std::strcmp(function_name, "SOLVE_GAME_STATE") == 0) {
            cin >> height; cin >> width; cin >> to_win; cin >> active_player;
            char** board = new char* [height];
            for (int i = 0; i < height; i++) {
                board[i] = new char[width];
            }
            putInputBoard(width, height, board);
            int result;
            if (active_player == '1') {
                result = minMax(width, height, to_win, board, true,0,-1000,1000);
            }
            else {
                result = minMax(width, height, to_win, board, false,0,-1000,1000);
            }
            //solveGame();
            if (result == -1)
                cout << P_2_WON << endl;
            else if (result == 1)
                cout << P_1_WON << endl;
            else if (result == 0)
                cout << TIE << endl;
        }
        else if (std::strcmp(function_name, "test") == 0) {
            int movex, movey;
            cin >> height; cin >> width; cin >> to_win; cin >> active_player; cin >> movex; cin >> movey;
            char** board = new char* [height];
            for (int i = 0; i < height; i++) {
                board[i] = new char[width];
            }
            putInputBoard(width, height, board);
            cout << evaluateNextMove(width, height, to_win, board, movex, movey);
            //genAllPosMoveCutIfGameOver();
        }
        else if (std::strcmp(function_name, "test2") == 0) {
            int movex, movey;
            cin >> height; cin >> width; cin >> to_win; cin >> active_player;
            char** board = new char* [height];
            for (int i = 0; i < height; i++) {
                board[i] = new char[width];
            }
            putInputBoard(width, height, board);
            cout << hasAnybodyWon(width, height, to_win, board) << endl;;
            printBoard(width, height, board);
            //genAllPosMoveCutIfGameOver();
        }
    }

    return 0;
}

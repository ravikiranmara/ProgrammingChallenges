#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int BoardSize = 8;
const int Gutter = 2;
const int TotalBoardSize = Gutter + BoardSize + Gutter;

const char InvalidCell = '*';
const char EmptyCell = '.';

const char BlackKing = 'k';
const char BlackQueen = 'q';
const char BlackKnight = 'n';
const char BlackRook = 'r';
const char BlackBishop = 'b';
const char BlackPawn = 'p';

const char WhiteKing = 'K';
const char WhiteQueen = 'Q';
const char WhiteKnight = 'N';
const char WhiteRook = 'R';
const char WhiteBishop = 'B';
const char WhitePawn = 'P';

typedef enum BoardDirection {
    WhiteTopToBottom, 
    WhiteBottomToTop
} BoardDirection;

class Board 
{
    char board[TotalBoardSize][TotalBoardSize];

  public:
    Board()
    {
        this->SetEmpty();
    }

    void ResetBoard() 
    {
        for(int i=0; i<TotalBoardSize; i++)
            for(int j=0; j<TotalBoardSize; j++)
                board[i][j] = EmptyCell;
    }

    void SetBoard(char board[BoardSize][BoardSize])
    {
        for (int i=0; i<BoardSize; i++)
            for(int j=0; j<BoardSize; j++)
                this->board[i+Gutter][j+Gutter] = board[i][j];
    }

    void DumpBoard()
    {
        for(int i=0; i<BoardSize; i++) {
            for(int j=0; j<BoardSize; j++)
                cout << this->board[Gutter+i][Gutter+j];
            cout <<endl;
        }
    }

    char GetPieceAtCell(int x, int y) 
    {
        char ret = InvalidCell;

        if(x < BoardSize && y < BoardSize) {
            ret = board[x+Gutter][y+Gutter];    
        }

        return ret;
    }
};

class Engine
{
    Board chessBoard;
    
  public:
    Engine () { }

    void ReadBoard() 
    {
        string line;
        char board[BoardSize][BoardSize];

        for(int i=0; i<BoardSize; i++) {
            getline(cin, line);
            strncpy(board[i], line.c_str(), BoardSize);
        }

        chessBoard.
        chessBoard.SetBoard(board);

        return;
    }

    void Run()
    {
        this->ReadBoard();

    }
};

int main ()
{
    Engine engine;

    engine->ReadBoard();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

inline void updateCell(char &pos) {
    if (pos == '.') pos = '+';
}

// unraveling the loop to avoid if statement check for 
// boundry cells in main loop.

// Complete the bomberMan function below.
vector<string> blowUp(vector<string> grid) {
    int row = grid.size();
    int col = grid[0].size();

/*
    // four corners
    if(grid[0][0] == 'O') { updateCell(grid[1][0]); updateCell(grid[0][1]); }
    if(grid[0][col-1] == 'O') { updateCell(grid[0][col-2]); updateCell(grid[1][col-1]); }
    if(grid[row-1][0] == 'O') { updateCell(grid[row-2][0]); updateCell(grid[row-1][1]); }
    if(grid[row-1][col-1] == 'O') { updateCell(grid[row-1][col-2]); updateCell(grid[row-2][col-1]); }

    // boundaries
    for (int i=1; i<row-1; i++) {
        if (grid[i][0] == 'O') {
            updateCell(grid[i-1][0]);
            updateCell(grid[i+1][0]);
            updateCell(grid[i][1]);
        }

        if (grid[i][col-1] == 'O') {
            updateCell(grid[i-1][col-1]);
            updateCell(grid[i][col-2]);
            updateCell(grid[i+1][col-1]);
        }
    }

    for (int i=1; i<col-1; i++) {
        if (grid[0][i] == 'O') {
            updateCell(grid[0][i-1]);
            updateCell(grid[0][i+1]);
            updateCell(grid[1][i]);
        }

        if (grid[row-1][i] == 'O') {
            updateCell(grid[row-1][i-1]);
            updateCell(grid[row-2][i]);
            updateCell(grid[row-1][i+1]);
        }
    }
*/

    // the inner cells
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (grid[i][j] == 'O') {
                if (i != 0) updateCell(grid[i-1][j]);
                if (j != 0) updateCell(grid[i][j-1]);
                if (i != row-1) updateCell(grid[i+1][j]);
                if (j != col-1) updateCell(grid[i][j+1]);
            }
        }
    }

    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++) 
            if (grid[i][j] == '.')  grid[i][j] = 'O';
            else if (grid[i][j] == 'O' || grid[i][j] == '+') grid[i][j] = '.';

    return grid;
}

bool isFullGrid(vector<string> grid) {
    bool flag = true;

    for (int i=0; i<grid.size() && flag == true; i++) 
        for (int j=0; j<grid[i].size() && flag == true; j++)
            if(grid[i][j] != '.') {
                flag = false;
            }

    return flag;
}

vector<string> fillGrid(vector<string> grid) {
    for (int i=0; i<grid.size(); i++) 
        for (int j=0; j<grid[i].size(); j++)
            grid[i][j] = 'O';

    return grid;
}

vector<string> bomberMan(int n, vector<string> grid) {
    n--;

    if (n == 0) return grid;
    
    if (n%2 == 1) return fillGrid(grid);

    if (n%2 == 0)
        grid = blowUp(grid);
    if (n%4 == 0)
        grid = blowUp(grid);

    return grid;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

// https://www.hackerrank.com/challenges/bomber-man

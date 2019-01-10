#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
    int tl=0, tr=0;
    for (int i=0, j=0; i<arr.size() && j<arr.size(); i++, j++) 
        tr += arr[i][j];
    for (int i=0, j=arr.size()-1; i<arr.size() && j>=0; i++,j--) 
        tl += arr[i][j];

    return std::abs(tl-tr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

//https://www.hackerrank.com/challenges/diagonal-difference

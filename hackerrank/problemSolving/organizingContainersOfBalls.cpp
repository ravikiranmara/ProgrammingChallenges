#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    // get row sum
    vector<int> rowSum;
    vector<int> colSum;
    colSum.resize(container.size(), 0);

    for (vector<int> row : container) {
        rowSum.push_back(std::accumulate(row.begin(), row.end(), 0));
        
        for (int col=0; col < row.size(); col++) {
            colSum[col] += row[col];
        }
    }   

    // sort rows and cols
    std::sort(rowSum.begin(), rowSum.end());
    std::sort(colSum.begin(), colSum.end());
 
    // debug print
    std::copy (rowSum.begin(), rowSum.end(), std::ostream_iterator<int>(std::cout, ","));
    cout << endl;
    std::copy (colSum.begin(), colSum.end(), std::ostream_iterator<int>(std::cout, ","));
    cout << endl;

    if (true == std::equal(rowSum.begin(), rowSum.end(), colSum.begin()))
        return "Possible";
    else return "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/organizing-containers-of-balls

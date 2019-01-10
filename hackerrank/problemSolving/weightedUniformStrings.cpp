#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<int> numberTable;
    vector<string> soln; 

    char currChar = s[0];
    int sum = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] != currChar) {
            currChar = s[i];
            sum = 0;
        }

        sum += s[i]-'a'+1;
        numberTable.push_back(sum);
    }

    for (auto i = queries.begin(); i!=queries.end(); i++) {
        if (std::find(numberTable.begin(), numberTable.end(), *i) != numberTable.end()) 
            soln.push_back("Yes");
        else 
            soln.push_back("No");
    }

    return soln;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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

// https://www.hackerrank.com/challenges/weighted-uniform-string

#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    vector<int> alpha;
    alpha.resize(26, 0);

    for (int i=0; i<s.size(); i++) 
        if (isalpha(s[i]))
            alpha[tolower(s[i]) - 'a'] = 1;


    return (std::accumulate(alpha.begin(), alpha.end(), 0) == 26) ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/pangrams

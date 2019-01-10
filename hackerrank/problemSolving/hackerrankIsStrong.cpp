#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string hackerrank = "hackerrank";

    int j=0; 
    for (int i=0; i<s.size(); i++) 
        if (s[i] == hackerrank[j]) {
            j++;

            if (j == hackerrank.size())
                break;
        }

    return j == hackerrank.size()? "YES" : "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/hackerrank-in-a-string

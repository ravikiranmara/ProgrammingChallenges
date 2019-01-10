#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    int i=1; 
    int j=0; 

    while (i<s.size()) {
        if (j==-1) {
            s[++j] = s[i++]; 
        } else if (s[j] == s[i]) {
            j--; i++;
        } else {
            s[++j] = s[i++]; 
        }
    }

    s.erase(j+1, s.size()-j);

    if (true == s.empty()) 
        s = "Empty String";

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/reduced-string

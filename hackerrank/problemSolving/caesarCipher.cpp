#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    for (int i=0; i<s.size(); i++) {
        if (islower(s[i]))
            s[i] = 'a' + (k+s[i]-'a')%26;
        else if (isupper(s[i])) 
            s[i] = 'A' + (k+s[i]-'A')%26;
    }

    return s;  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/caesar-cipher-1

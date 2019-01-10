#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    // remove spaces
    auto last = std::remove(s.begin(), s.end(), ' ');
    s.erase(last, s.end());

    // chop chop
    int length = s.size();
    int low = std::floor(std::sqrt(length));
    int high = std::ceil(std::sqrt(length));

    // code it up
    string code; 
    for (int i=0; i<high; i++) {
        for (int j=0; i+j<length; j+=high) 
            code.push_back(s[i+j]);

        code.push_back(' ');
    }

    return code;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/encryption

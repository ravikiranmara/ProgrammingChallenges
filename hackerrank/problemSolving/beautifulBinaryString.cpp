#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
    auto i=0; 
    auto count = 0;
    bool seen = false;

    for (auto i=0; i<=b.size()-3; i++) {
        if ('0' == b[i] && '1' == b[i+1] && '0' == b[i+2]) {
            i+=1;
            if (false == seen) {
                seen = true;
                count++;
            } else {
                seen = false;
            }
        } else {
            seen = false;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/beautiful-binary-string

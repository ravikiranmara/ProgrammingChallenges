#include <bits/stdc++.h>

using namespace std;

long long makeNumber(string s, int i, int j) {
    long long ret = 0;

    while (i <= j) {
        ret = ret * 10 + s[i]-'0';
        i++;
    }

    // cout << "maneNum : " << ret << " ";
    return ret;
}

// Complete the separateNumbers function below.
// integers can't hold large numbers
void separateNumbers(string s) {
    long long seed = 0;
    long long nextNumber = 0;
    long digReq = 0;
    string status = "NO\n";
    bool notPretty = false;

    for (int i=0; i<s.size()/2; i++) {
        long j=i;
        seed = makeNumber(s, 0, j);
        notPretty = false;

        while (j<s.size()) {
            // cout << "start seed : " << seed << endl;
            nextNumber = seed + 1;
            digReq = std::floor(std::log10(nextNumber*10));

            if (j+digReq >= s.size()) {
                notPretty = true;
                break;
            }

            seed = makeNumber(s, j+1, j+digReq);
            // cout << nextNumber << "-" << seed  << ": ";
            if (seed == nextNumber) 
                j += digReq;
            else {
                notPretty = true;
                break;
            }

            if (j == s.size()-1)
                break;

        }

        if (notPretty == false) {
            status = "YES " + s.substr(0, i+1) + "\n";
            break;
        }
    }

    cout << status; 
    return ;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}

// https://www.hackerrank.com/challenges/separate-the-numbers

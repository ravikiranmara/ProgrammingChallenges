#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    auto forward = s.begin(); 
    auto backward = s.end()-1;
    auto funny = true;

    while (backward != s.begin()) {
        cout << *forward<< " ";
        if (abs(*forward-*(forward+1)) == abs(*(backward-1) - *backward)) {
            forward++; backward--;
        } else {
            funny = false;
            break;
        }
    }

    return (funny == true)? "Funny" : "Not Funny";

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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/funny-string

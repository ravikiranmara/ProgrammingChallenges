#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    vector<int> scount;
    int count; 

    scount.resize(26, 0);

    for_each (s.begin(), s.end(), [&scount](char i){ scount[i-'a']++; });
    count = std::count_if(scount.begin(), scount.end(), [](int i) { return (i%2==1)?true:false;});

    return (count > 1) ? "NO" : "YES";
    // std::copy(scount.begin(), scount.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/game-of-thrones

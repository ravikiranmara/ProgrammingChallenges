#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if (s.size() % 2 == 1) {
        return -1;
    }

    vector<int> s1, s2;
    s1.resize(26, 0);
    s2.resize(26, 0);

    auto j = s.size()-1;
    for (int i=0; i<s.size()/2; i++, j--) {
        s1[s[i]-'a']++;
        s2[s[j]-'a']++;
    }

    for (int i=0; i<s1.size(); i++) {
        s1[i] = abs(s1[i]-s2[i]);
    }

    return std::accumulate(s1.begin(), s1.end(), 0)/2;
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/anagram

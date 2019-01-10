#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    vector<int> s1count;
    vector<int> s2count;

    s1count.resize(26, 0);
    s2count.resize(26, 0);
     
    // for_each(s1.begin(), s1.end(), [&s1count] (auto p) {s1count[*p - 'a']++; });
    for (int i=0; i<s1.size(); i++) 
        s1count[s1[i] - 'a']++;
        
    for (int i=0; i<s2.size(); i++) 
        s2count[s2[i] - 'a']++;

    int count = 0;
    for (int i=0; i<26; i++) 
        count += std::abs(s1count[i] - s2count[i]);

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/making-anagrams

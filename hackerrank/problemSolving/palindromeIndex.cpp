#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s, int start, int end) {
    bool ret = true;

    for (   ; start < end && s[start] == s[end]; start++, end--) 
        ;

    return (start < end)? false:true;
}

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    auto i = 0; 
    auto j = s.size() - 1;

    if (true == isPalindrome(s, i, j)) 
        return -1;
    
    int ret = -1;
    while (i < j) {
        if (s[i] == s[j]) {
            i++; j--;
            continue;
        } 

        if (true == isPalindrome(s, i, j-1)) 
            ret = j; 
        else if (true == isPalindrome(s, i+1, j)) 
            ret = i; 
        
        break; 
    }

    return ret;
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/palindrome-index

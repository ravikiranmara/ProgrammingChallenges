#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    // I am not even thinking.. :(
    int temp;
    
    temp = s[0]-'0';
    temp *= 10;
    temp += (s[1]-'0');
    cout << temp << endl;
    
    if ('P' == s[8]) {
        temp += 12;
        if (temp == 24) temp = 12;
     } else {
        if (temp == 12)
            temp = 0;
    }
    
    s[0] = (temp/10)+'0';
    s[1] = (temp%10)+'0';
    string ret = s.substr(0, 8);
    
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

//https://www.hackerrank.com/challenges/time-conversion

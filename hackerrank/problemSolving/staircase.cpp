#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    int lead = n-1;
    int numPrint = 1;
    
    while (numPrint <= n) {
        for (auto j=0; j<lead; j++) 
            cout << " ";
        for (auto j=0; j<numPrint; j++) {
            cout << "#";
        }
        cout << endl;
        lead--;
        numPrint++;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}

// https://www.hackerrank.com/challenges/staircase

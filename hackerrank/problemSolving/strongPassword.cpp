#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int lower = 0; 
    int upper = 0;
    int symbol = 0;
    int number = 0;
    
    for (int i=0; i<n; i++) 
        if (isupper(password[i])) {
            upper = 1; 
            break; 
        }

    for (int i=0; i<n; i++) 
        if (islower(password[i])) {
            lower = 1; 
            break; 
        }
    for (int i=0; i<n; i++) 
        if (isdigit(password[i])) {
            number = 1; 
            break; 
        }
 
     for (int i=0; i<n; i++) 
        if (password[i] == '!' || password[i] == '@' || 
            password[i] == '#' || password[i] == '$' || 
            password[i] == '%' || password[i] == '^' || 
            password[i] == '&' || password[i] == '*' || 
            password[i] == '(' || password[i] == ')' || 
            password[i] == '-' || password[i] == '+') {
            symbol = 1; 
            break; 
        }

    return std::max(4-number-upper-lower-symbol, 6-n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/strong-password

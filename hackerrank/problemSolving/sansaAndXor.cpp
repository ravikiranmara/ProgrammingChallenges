#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

    /* this solves a different problem
    int arrsize = arr.size();
    int counter = std::pow(2, arrsize)-1;
    
    int finxor = 0;
    while (counter > 0) {
        int minxor = 0;
        int spot1 = 1;
        for (int i=arrsize-1; i>=0; i--) {
            if (counter&spot1) {
                cout << "xor : " << i << endl;
                minxor ^= arr[i];
            }
            spot1 <<=1;
        }
        finxor ^= minxor;
        counter--;
        cout << counter << ":" << minxor << "-" << finxor << endl;
    }

    return finxor;
    */

/*  // I should've known, brute force would timeout
    int finxor = 0;
    for (int i=1; i<=arr.size(); i++) {
        for (int j=0; j<=arr.size()-i; j++) {
            int minxor = 0;
            for (int k=j; k<j+i; k++) {
                // cout << k << ",";
                minxor ^= arr[k];
            }
            // cout << endl;
            finxor ^= minxor;
        }
    }
    
    return finxor;
    */

// Complete the sansaXor function below.
int sansaXor(vector<int> arr) {
    // is xor transitive?
    // xor result is the xor of odd occurances. Given the 
    // sequence, can it be predicted?

    int finxor = 0;
    if (1 == arr.size()%2) {
        for (int i=0; i<arr.size(); i+=2) 
            finxor ^= arr[i]; 
    } else {
        finxor = 0;
    }
    
    return finxor;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = sansaXor(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

// https://www.hackerrank.com/challenges/sansa-and-xor

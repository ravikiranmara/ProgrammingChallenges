#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    vector<int> alphabet; 
    alphabet.resize(26, 0);

    for (int i=0; i<arr.size(); i++) {
        std::sort(arr[i].begin(), arr[i].end());
        auto last = std::unique(arr[i].begin(), arr[i].end());
        for (auto j=arr[i].begin(); j != last; j++) {
            alphabet[*j - 'a']++;
        }
        cout << endl;
    }

    // std::copy (alphabet.begin(), alphabet.end(), ostream_iterator<int>(cout, " "));

    int count = 0;
    for (auto i = alphabet.begin(); i != alphabet.end(); i++)
        if (*i == arr.size()) 
            count++;

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/gem-stones

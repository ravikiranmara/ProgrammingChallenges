#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    auto high = w.begin();
    bool assigned = false;

    for (auto i=w.begin(); i+1!=w.end(); i++) {
        if (*i < *(i+1)) {
            high = i;
            assigned = true;
            // cout << "assigned" << *i << ":" << *(i+1)<< endl;
        }
    }

    if (assigned == true) {
        // find the lowest child
        // auto lowest = std::min_element(high+1, w.end());

        auto lowest = high+1;
        for (auto it = high+1; it != w.end(); it++)
            if (*it < *lowest && *it > *high) 
                lowest = it;

        // cout << *lowest << ":lowest" << endl;
        // swap lowest
        char temp = *high;
        *high = *lowest;
        *lowest = temp;

        // sort to get next number 
        std::sort(high+1, w.end());
        return w;
    } 

    return "no answer";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/bigger-is-greater

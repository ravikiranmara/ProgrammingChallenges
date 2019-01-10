#include <bits/stdc++.h>

using namespace std;

// Complete the winningLotteryTicket function below.
long winningLotteryTicket(vector<string> tickets) {
    long ret = 0;
    vector<long> bitCount;
    vector<int> mask = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int fullmask = std::accumulate(mask.begin(), mask.end(), 0);
    
    // remove duplicates and sort
    bitCount.resize(fullmask+1, 0);
    for (auto &t : tickets){
        auto dup = std::unique(t.begin(), t.end());
        
        int bit = 0;
        for (auto i=t.begin(); i!=dup; i++) {
            bit |= mask[*i-'0'];
        }
        ++bitCount[bit];
    }
    
   ret = 0;
    for (int i=mask[mask.size()-1]; i<fullmask; i++) {
        if (bitCount[i]==0) continue;
        for (int j=1; j<i; j++) {
            if (bitCount[j]==0) continue;
            int sum = i | j;
            if (sum == fullmask) {
                ret += (bitCount[i] * bitCount[j]);
            }
        }
    }
    
    long notall = tickets.size() - bitCount[fullmask];
    long maskcount = (bitCount[fullmask] * (bitCount[fullmask]-1))/2;
    ret += maskcount;
    ret += bitCount[fullmask] * notall;
    
    cout << ret << endl;
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> tickets(n);

    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);

        tickets[i] = tickets_item;
    }

    long result = winningLotteryTicket(tickets);

    fout << result << "\n";

    fout.close();

    return 0;
}

// https://www.hackerrank.com/challenges/winning-lottery-ticket

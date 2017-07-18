#include <iostream>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::accumulate;
using std::vector;

class HartalCalculator {
    int numParties;
    int numDays;
    vector<int> hartalInterval;
    vector<int> hartalDays;

    void reset() {
        numParties = 0;
        hartalInterval.clear();
    }

  public:
    HartalCalculator() {
        this->reset();
    }

    void Reset() {
        this->reset();
    }

    bool ReadInput() {
        // num days
        cin >> numDays;
        hartalDays.clear();
        hartalDays.resize(numDays, 0);

        // num parties
        cin>>numParties;
        hartalInterval.resize(numParties, 0);

        // hartal number for each party
        for(int i=0; i<numParties; i++) {
            cin >> hartalInterval[i];
        }

        return true;
    } 

    int Calculate() {
        // calculate hartal for each party
        for(int i=0; i<numParties; i++) {
            int hd = hartalInterval[i]; 
            int j = -1; 
            if(hd > 0) {
                while((j+hd)<numDays) {
                    j += hd;
                    hartalDays[j] = 1;
                } 
            }
        }

        // remove weekend days
        int j=5; 
        while(j < numDays) {
            hartalDays[j] = 0; 
            if(j+1 < numDays) {
                hartalDays[j+1] = 0; 
            }

            j+=7;
        }

        return accumulate(hartalDays.begin(), hartalDays.end(), 0); 

    }

    void DumpHartalDays() {
        for(int i=0; i<numDays; i++) {
            cout << hartalDays[i] << "(" << i << ") -- ";
        }
        cout << endl;
    }

};

int main(int argc, char *argv[]) {
    int numCases = 0; 
    HartalCalculator hartalCalculator;    

    // read num bases
    cin >> numCases;

    // read each case
    for(int i=0; i<numCases; i++) {
        hartalCalculator.Reset();
        hartalCalculator.ReadInput();
        cout << hartalCalculator.Calculate() << endl;
    }

    return 0;
}

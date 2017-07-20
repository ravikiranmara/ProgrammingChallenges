#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

const int maxShuffleTypes = 100; 
const int numCardsInDeck = 52;

class Shuffler {
    string nameOfCard[numCardsInDeck] = { "2 of Clubs", "3 of Clubs", "4 of Clubs", "5 of Clubs", "6 of Clubs", "7 of Clubs", "8 of Clubs", "9 of Clubs", "10 of Clubs", "Jack of Clubs", "Queen of Clubs", "King of Clubs", "Ace of Clubs",
        "2 of Diamonds", "3 of Diamonds", "4 of Diamonds", "5 of Diamonds", "6 of Diamonds", "7 of Diamonds", "8 of Diamonds", "9 of Diamonds", "10 of Diamonds", "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds", "Ace of Diamonds",
        "2 of Hearts", "3 of Hearts", "4 of Hearts", "5 of Hearts", "6 of Hearts", "7 of Hearts", "8 of Hearts", "9 of Hearts", "10 of Hearts", "Jack of Hearts", "Queen of Hearts", "King of Hearts", "Ace of Hearts",
        "2 of Spades", "3 of Spades", "4 of Spades", "5 of Spades", "6 of Spades", "7 of Spades", "8 of Spades", "9 of Spades", "10 of Spades", "Jack of Spades", "Queen of Spades", "King of Spades", "Ace of Spades" };

    int knownShuffleTypes[maxShuffleTypes][numCardsInDeck];
    int numShuffles;

    int *currentDeck, *tempDeck;

    void resetDeck() {
        // set to unsorted deck
        for(int i=0; i<numCardsInDeck; i++) {
            currentDeck[i] = i;
            tempDeck[i] = i;
        }
    }
    
    void reset() {
        numShuffles = 0; 
        for(int i=0; i<maxShuffleTypes; i++) {
            for(int j=0; j<numCardsInDeck; j++) {
                knownShuffleTypes[i][j] = -1;
            }
        }

        this->resetDeck();
    }

    void dumpCurrentDeckByNumber() {
        for(int i=0; i<numCardsInDeck; i++) 
            cout << currentDeck[i] << " ";
        cout << endl;
    }

  public:
    Shuffler() {
        currentDeck = new int[numCardsInDeck];
        tempDeck = new int[numCardsInDeck];

        this->reset(); 
    }

    ~Shuffler() {
        delete currentDeck;
        delete tempDeck;
    }

    void Reset() {
        this->reset(); 
    }

    void ReadInput() {
        // read num shuffles
        cin >> numShuffles;

        // read each of shuffle patterns
        for(int i=0; i<numShuffles; i++) {
            for(int j=0; j<numCardsInDeck; j++) {
                cin >> knownShuffleTypes[i][j];
                knownShuffleTypes[i][j]--;
            }

             // cout << "read shuffle : " << i << endl;
        }
    }

    int Shuffle (vector<int> order) {
        // this->dumpCurrentDeckByNumber();
        for(int i=0; i<order.size(); i++) {
            // cout << "order : " << order[i] << endl;
            for(int j=0; j<numCardsInDeck; j++) {
                tempDeck[j] = currentDeck[knownShuffleTypes[order[i]][j]];
            }
            
            int *tempTemp = currentDeck;
            currentDeck = tempDeck;
            tempDeck = tempTemp;

            // this->dumpCurrentDeckByNumber();
        }

        // swap out decks, usng pointers instead of full copy
        return 0; 
    }

    void DumpCurrentDeck() {
        for(int i=0; i<numCardsInDeck; i++) {
            cout << nameOfCard[currentDeck[i]] << endl;
        }
    }

    void DumpKnownShuffles() {
        for (int i=0; i<numShuffles; i++) {
            cout << "shuffle : " << i << endl;
            for(int j=0; j<numCardsInDeck; j++) {
                cout << knownShuffleTypes[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    Shuffler shuffler;

    string line;
    stringstream str;

    
    int numTests;
    line.clear();
    str.clear();

    getline(cin, line);
    str << line;
    str >> numTests;
    // cout << "numTests:" << numTests << endl;

    string eatBlank;
    vector<int> shuffleOrder;
    string shuffleKey;
    string emptyString = "";
     
    // eat blank
    getline(cin, line);
    line.clear();

    for(int i=0; i<numTests; i++) {
        line.clear();
        str.clear();

        shuffleOrder.clear();

        shuffler.Reset();
        shuffler.ReadInput();
        // shuffler.DumpKnownShuffles();

        getline(cin, line);

        // read shuffle sequence
        while(true) {
            line.clear();
            str.clear();

            // eat blank
            getline(cin, line);
            // cout << "read line : " << endl;
            if(true == line.empty()) {
                break; // end of input for shuffle sequence
            } else { 
                str << line;
                str >> shuffleKey;
                // cout << shuffleKey << endl;
                int shuffleNum = atoi(shuffleKey.c_str());
                // cout << "shuffle Num : " << shuffleNum << endl;
                shuffleOrder.push_back(atoi(shuffleKey.c_str()) - 1); // zero indexed
            }
        }

        // simulate shuffle
        shuffler.Shuffle(shuffleOrder);

        // print output
        shuffler.DumpCurrentDeck();
        if(i!=numTests-1) {
            cout << endl;
        }
    }

    return 0;
}

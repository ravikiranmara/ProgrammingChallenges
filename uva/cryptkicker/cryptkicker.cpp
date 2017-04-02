#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;
using std::stringstream;

const int AlphaLength = 26;

struct StringLengthCompare {
    bool operator() (const string& first, const string& second) {
        return first.size() > second.size();
    }
};

class CryptDecoder
{
    vector<string> dictionary;

    void sortStringByLength() {

    }

public:
    CryptDecoder() {
        this->reset();
    }

    void reset() {
        dictionary.clear();
    }

    int readDictionary() {
        int numWords = 0;
        string strWords;
        stringstream strstrWords;
        StringLengthCompare compare;

        // num words
        getline(cin, strWords);
        strstrWords << strWords;
        strstrWords >> numWords;

        // read words
        string word;
        for(auto i=0; i<numWords; i++) {
            word.clear();
            getline(cin, word);
            this->dictionary.push_back(word);
        }

        std::sort(this->dictionary.begin(), this->dictionary.end(), compare);
    }

    int addToDictionary(vector<string> &words) {
        for (auto &w : words) {
            dictionary.push_back(w);
        }
    }

    int addToDictionary(string word) {
        dictionary.push_back(word);
    }
    
    bool isConflict(string &word, string &dict, vector<char> &alphabet) {
        int size = word.size();
        int alpha; 
        vector<char> assume;
        assume.resize(AlphaLength, '.');
        if(size != dict.size()) 
            return true;

        for(int i=0; i<size; i++) {
            if(((alphabet[word[i] - 'a'] == dict[i]) || 
                    (alphabet[word[i] - 'a'] == '.' && alphabet.end() == std::find(alphabet.begin(), alphabet.end(), dict[i]))) &&
                    (assume[word[i] - 'a'] == dict[i] || assume[word[i] - 'a'] == '.')) {
                //cout << dict[i] << "-" << word[i] << "-" << assume[i] << endl;
                assume[word[i] - 'a'] = dict[i];
                continue;
            }
            else {
                // cout << "return true\n";
                return true;
            }
        }

        // cout << "return false\n";
        return false;
    }

    void makeMap(string &word, string &dict, vector<char> &map, vector<char> &alphabet) {
        for(int i=0; i<word.size(); i++) {
            int mappos = word[i]-'a';
            if(alphabet[mappos] == '.') {
                map[mappos] = dict[i];
                alphabet[mappos] = dict[i];
            }
        }
    }

    void resetMap(vector<char> &map) {
        for(auto &a:map) 
            a='.';
    }

    void unmakeMap(vector<char> &map, vector<char> &alphabet) {
        for(auto a:map) 
            alphabet[a-'a'] == '.';
    }

    bool findMatch(vector<string> &line, int w, vector<char> &alphabet) {
        vector<char> newmap;
        int d = 0;

        if(line.size() == w) {
            return true;
        }

        newmap.resize(AlphaLength, '.');
        // cout << "findmatch :: enter" << "(" << w <<"):" << line[w] << endl; 

        string word = line[w];
        for(auto &d:this->dictionary) {
            //cout << "examine:" << d << " <=>" << word << endl;
            if(!this->isConflict(word, d, alphabet)) {
                 //cout <<"no conflict" << endl << std::flush;
                 makeMap(word, d, newmap, alphabet);
                 if(false == findMatch(line, w+1, alphabet)) {
                     unmakeMap(newmap, alphabet);
                     this->resetMap(newmap);
                 } 
                 else return true;
             }
             //else cout << "conflict" << endl;
        }

        return false;
    } 

    int decode(string& sentence) {
        StringLengthCompare compare;
        stringstream ssen(sentence);
        vector<string> line;
        string tok;
        char delim = ' ';
        vector<char> alphabet;
        alphabet.resize(AlphaLength, '.');

        // read input lines
        while(getline(ssen, tok, delim)) {
            line.push_back(tok);
        }

        // process line
        std::sort(line.begin(), line.end());
        line.erase(std::unique(line.begin(), line.end()), line.end());
        std::sort(line.begin(), line.end(), compare);
        // dbgDumpVector(line);

        // start decode
        if(true == this->findMatch(line, 0, alphabet))
            this->printDecodedMessage(sentence, alphabet);
        else    this->printStars(sentence);

        // dbgDumpAlphabet(alphabet);
    }
    
    void printStars(string sentence) {
        for(auto a:sentence) {
            if(' ' != a) cout <<"*";
            else cout << a;
        }
        cout << endl;
    }

    void printDecodedMessage(string sentence, vector<char> &alphabet) {
       for(auto a:sentence) {
            if(a != ' ') cout << alphabet[a-'a'];
            else cout<<a;
       } 
       cout << endl;
    }

    void dbgDumpAlphabet(vector<char> alphabet) {
        int i=0; 
        cout <<"Alphabet mapping" << endl;
        for(auto a:alphabet)
            cout << (char)(i + 'a') << " - " << a << ",";
        cout << endl;
    }

    void dbgDumpVector(vector<string> &str) {
         for (string &v : str) {
            cout << v << endl;
        }

    }

    void dbgDump() {
        cout << "Number of words in dictionary : " << this->dictionary.size() << endl;
        for (string &v : this->dictionary) {
            cout << v << endl;
        }
    }
};


int main(int argc, char *argv[])
{
    int numInstances = 0;
    string line;
    CryptDecoder cryptDecoder;

    cryptDecoder.readDictionary();
    // cryptDecoder.dbgDump();

    line.clear();
    while(getline(cin, line)) {
        if(line.empty())
            break;

        // cout << "(" << line.size() << ")" << line << endl; 
        cryptDecoder.decode(line);
        line.clear();
    }
}
 

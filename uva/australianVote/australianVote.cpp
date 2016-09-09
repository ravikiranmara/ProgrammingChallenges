#include <iostream>
#include <sstream> 
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

const int MaxCandidates = 20;
const int MaxVotes = 1000;
const int MaxCandidateName = 81;

bool ReadCandidateNames(char candidates[MaxCandidates][MaxCandidateName], bool validCandidate[MaxCandidates], int n)
{
	bool rval = true;
	char tempname[81];
	
	for(int i=0; i<n; i++) {
		cin >> tempname;
		strncpy(candidates[i], tempname, MaxCandidateName);
        validCandidate[i] = true;
	}
	
	return rval;
}

bool DumpCandidateNames(char candidates[MaxCandidates][MaxCandidateName], bool validCandidate[MaxCandidates], int n)
{
    for(int i=0; i<n; i++) 
        cout << candidates[i] << ":" << validCandidate[i] << endl;
}

void MakeAllCandidateInvalid(bool validCandidate[MaxCandidates])
{
    for(int i=0; i<MaxCandidates; i++) {
        validCandidate[i] = false;
    }
}

int ReadVotes(int votes[MaxVotes][MaxCandidates], int n)
{
    std::string line;
	std::stringstream sline;
	
	int i=0;
	while(std::getline(cin, line)) {
		if(line.length() == 0) {
            cout << "emptyline" << endl;
			break;
        }
		
        sline.str(line);
		for(int j=0; j<n; j++) {
			sline >> votes[i][j];
		}
		
		i++;
	}
	
	return i;
}

void DumpVotes(int votes[MaxVotes][MaxCandidates], int numCandidate, int numVotes)
{
    for(int i=0; i<numVotes; i++) {
        for(int j=0; j<numCandidate; j++) 
            cout << votes[i][j] <<" ";
        cout << endl;
    }
}

void SetVotesToZero(int votesCandidate[MaxCandidates], int numCandidate)
{
    for(int i=0; i<numCandidate; i++) {
        votesCandidate[i] = 0;
    }

    return;
}

int GetValidVote(int vote[MaxCandidates], bool validCandidate[MaxCandidates], int numCandidate)
{
    for (int i=0; i<numCandidate; i++) {
        if(validCandidate[vote[i]] != false)
            return vote[i];
    }
        
    return -1; // this should never happen
}

int countVotes(int votes[MaxVotes][MaxCandidates], int votesCandidate[MaxCandidates], bool validCandidate[MaxCandidates], int numVotes, int numCandidate)
{
    SetVotesToZero(votesCandidate, numCandidate);

    for(int i=0; i<numVotes; i++) {
        votesCandidate[GetValidVote(votes[i], validCandidate, numCandidate)] += 1;
    }

    return 0;
}

bool IsWinner(int votesCandidate[MaxCandidates], int numCandidate, int &candidate) 
{
    int max = 0;
    int tempcandidate = -1;

    for(int i=0; i<numCandidate; i++) {
        if(max < votesCandidate[i]) {
            max = votesCandidate[i];
            tempcandidate = i;
        }
    }

    if((float)max/numCandidate > 0.5) {
        candidate = tempcandidate;
        return true;
    }

    return false;
}

int RemoveCandidates(bool validCandidate[MaxCandidates], int candidate) {
    validCandidate[candidate] = false;
}

int main(int argc, char* argv[]) 
{
	int numInput;
	int numCandidate;
    int numVotes;
	int votes[MaxVotes][MaxCandidates];
	char candidates[MaxCandidates][MaxCandidateName];
    bool validCandidate[MaxCandidates];
    int votesCandidate[MaxCandidates];
	std::stringstream sline;
    std::string line;
	
	std::getline(cin, line);
    sline.str(line);
	sline >> numInput;
	
	std::getline(cin, line); // chomp empty line
	
	for(int i=0; i<numInput; i++) {
        MakeAllCandidateInvalid(validCandidate);

		cin >> numCandidate;
		
		ReadCandidateNames(candidates, validCandidate, numCandidate);
        DumpCandidateNames(candidates, validCandidate, numCandidate);

		numVotes = ReadVotes(votes, numCandidate);
		DumpVotes(votes, numCandidate, numVotes);
		
	}
	
}

     
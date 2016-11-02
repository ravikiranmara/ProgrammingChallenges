#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::list;
using std::vector;

const int MaxLength = 81;

class Candidate {
	string name;
	bool inrace;
	int voteCount;
	int id;

public:
	Candidate(string name, int id) {
		this->name = name;
		inrace = true;
		voteCount = 0;
		this->id = id;
	}

	string GetName() {
		return name;  
	}

	void Discard() {
		inrace = false;
		voteCount = -1;
	}

	void ResetVote() {
		if(this->inrace)
			voteCount = 0;
	}

	int GetVoteCount() {
		return voteCount;
	}

	int AddVote() {
		return ++voteCount;
	}

	bool InRace() {
		return this->inrace;
	}

	int GetId() {
		return id;
	}

	void dumpCandidate() {
		cout << "name : " << this->GetName() << endl;
		cout << "id : " << this->GetId() << endl;
		cout << "inRace : " << this->InRace() << endl;
		cout << "vote count : " << this->GetVoteCount() << endl;
	}
};

class Ballot
{
	vector<Candidate> candidates;
	vector<list<int>> allvotes;
	int numCandidatesInRace;
	int maxVote; 
	
	void countVotes() {
		this->maxVote = 0;
		// cout << "all votes : " << allvotes.size() << endl;

		for (auto &c : candidates) {
			c.ResetVote();
		}

		for (auto &vote : allvotes) {
			candidates[vote.front() - 1].AddVote();
			maxVote = std::max
                (maxVote, candidates[vote.front() - 1].GetVoteCount());
		}

		// cout << "Count vote exit" << endl;
	}

	void DiscardCandidate(int i) {
		for(auto &v : allvotes) {
			v.remove(i+1);
		}
		candidates[i].Discard();
		numCandidatesInRace--;
	}

public:
	Ballot() {  }

	void Reset() {
		numCandidatesInRace = 0;
		maxVote = -1;
		candidates.clear();
		allvotes.clear();
	}
	
	void ReadCandidateNames(int n)
	{
		string str;
		for (int i = 0; i < n; i++) {
			getline(cin, str);
			candidates.push_back(Candidate(str, i));
		}

		numCandidatesInRace = candidates.size();
		// cout << "read all candidates" << endl;
	}

	void ReadVotes()
	{
		string line;
		stringstream str;
		int numCandidates = candidates.size();

		while (true) {
			line.clear();
			str.clear();

			getline(cin, line);
			if (line.empty()) {
				//cout << "break" << line;
				break;
			}
			
			str << line;
			
			int temp;
			list<int> vote;
			for (int i = 0; i < numCandidates; i++) {
				str >> temp;
				//cout << "pushing temp: " << temp;
				vote.push_back(temp);
			}

			allvotes.push_back(vote);
		}
	}

	vector<Candidate> GetWinner() {
		vector<Candidate> tiedCandidates;

		this->countVotes();

		for (auto &c : candidates) {
			if (c.GetVoteCount() == maxVote) {
				tiedCandidates.push_back(c);
			}
		}
		// cout << "Get Winner exit : " << maxVote << endl;

		return (tiedCandidates.size() == numCandidatesInRace)? 
								tiedCandidates : vector<Candidate>();
	}

	void DiscardCandidatesWithLeastVote() {
		int leastVotes = maxVote;
		vector<Candidate> tiedCandidates;

		for (auto &c : candidates) {
			if (c.InRace()) {
				leastVotes = std::min(leastVotes, c.GetVoteCount());
			}
		}

		// cout << "least vote : " << leastVotes << endl;
		for (auto &c : candidates) {
			if (c.GetVoteCount() == leastVotes) {
				this->DiscardCandidate(c.GetId());
			}
		}
	}

	void dumpCandidate()
	{
		cout << "---- Candidate dump ----" << endl;
		for (auto &c : candidates) {
			c.dumpCandidate();
			cout << endl;
		}

	}

	void voteDump() {
		cout << "--- vote dump ---" << endl;
		for (auto &v : allvotes) {
			for (auto &i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
	}

	void dumpBallot()
	{
		dumpCandidate();
		voteDump();
	}
};

int main(int argc, char *argv[])
{
	int numcases = 0;
	int numCandidates = 0;
	stringstream linestr;
	string line;
	Ballot ballot;
	vector<Candidate> winners;
	vector<Candidate> tempwinner;

	// read line
	getline(cin, line);
	linestr << line;

	// eat blank line
	getline(cin, line);

	linestr >> numcases;
	while (numcases > 0) {
		numcases--;

		line.clear();
		linestr.clear();
		getline(cin, line);
		linestr << line;
		linestr >> numCandidates;

		// cout << numCandidates;

		ballot.Reset();
		ballot.ReadCandidateNames(numCandidates);
		ballot.ReadVotes();

		while (true) {
			winners = ballot.GetWinner();
			// cout << "Get Wnners" << winners.size() << endl;
			//ballot.dumpBallot();

			if (0 != winners.size())
				break;

			ballot.DiscardCandidatesWithLeastVote();
		}

		for (auto &c : winners) {
			cout << c.GetName() << endl;
		}

		if(0 != numcases)
			cout << endl;
	}

	return 0;
}
/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Wednesday May 6, 2020

		 CS A250
		 Project 1 - Part B
*/

#include "CandidateList.h"
#include <utility>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

// Function declarations
// Same order as in class definition

void CandidateList::addCandidate(const CandidateType& candidate)
{
	candidates.push_back(candidate);
}

int CandidateList::getWinner() const
{
	//// If --count is 0...

		list<CandidateType>::const_iterator iter = candidates.begin();
		
		int winnerID = 0;
		int winnerTtlVotes = 0;

		while (iter != candidates.end())
		{
			if (winnerTtlVotes < iter->getTotalVotes())
			{
				winnerTtlVotes = iter->getTotalVotes();
				winnerID = iter->getID();
			}
			iter++;
		}
		return winnerID;
}

bool CandidateList::isEmpty() const
{
	// Use ternary operator...
	return candidates.empty() ? true : false;
}

// Public Search function
bool CandidateList::searchCandidate(int ID) const
{
	list<CandidateType>::const_iterator firstObj = candidates.begin();
	return CandidateList::searchCandidate(ID, firstObj);
}

void CandidateList::printCandidateName(int ID) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	searchCandidate(ID, iter);
	iter->printName();
}

void CandidateList::printAllCandidates() const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	list<CandidateType>::const_iterator iterEnd = candidates.end();

	while (iter != iterEnd)
	{
		iter->printID();
		cout << " - " << iter->getLastName() 
			<< ", " << iter->getFirstName() << "\n";
		iter++;
	}
}

void CandidateList::printKingdomVotes(int ID, int kingdom) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();
	
	if (CandidateList::searchCandidate(ID, iter))
	{
		cout << right << setw(5) << setfill(' ')
			<< "*" << setw(3) << iter->getVotesByKingdom(kingdom)
			<< "( => )" << KINGDOMS[kingdom] << "\n";
	}
}

void CandidateList::printCandidateTotalVotes(int ID) const
{
	list<CandidateType>::const_iterator iter = candidates.begin();

	if (CandidateList::searchCandidate(ID, iter))
	{
		cout << "    => Total votes: "
			<< iter->getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const
{
	// Create a Map containing <--totalVotes, pair<--lastName, --firstName>>
	// Map has a nested Pair for ease of access to Name
	map<int, pair<string, string>> candMap; 

	list<CandidateType>::const_iterator iter = candidates.begin();
	list<CandidateType>::const_iterator iterEnd = candidates.end();

	while (iter != iterEnd)
	{
		// Creation of Map to gather info for output in Order
		// Will have to create a reverseIterator() 
		candMap.insert(make_pair(iter->getTotalVotes(),
					make_pair(iter->getLastName(),
								iter->getFirstName())));
		iter++;
	}

	printHeader();

	int candidatePOSition = 0;
	map<int, pair<string, string>>::
		const_reverse_iterator revIter = candMap.crbegin();

	for (revIter; revIter != candMap.crend(); ++revIter)
	{
		candidatePOSition++;

		// Use reverseIterator here
		cout << left << setw(15) << setfill(' ')
			<< revIter->second.first << setw(12)
			<< revIter->second.second << setw(3)
			<< revIter->first << right << setw(7)
			<< candidatePOSition << "\n";

		// Put dashes in between every 5 Candidates
		if ((candidatePOSition > 4) && (!(candidatePOSition % 5)))
			cout << right << setw(40) << setfill('-') << "-\n";
	}
}

// Destructor Method
CandidateList::~CandidateList(){}

// Overloaded Private Search function
bool CandidateList::searchCandidate(int ID, 
	list<CandidateType>::const_iterator iter) const
{
	list<CandidateType>::const_iterator endObj = candidates.end();
	iter = find(iter, endObj, ID);
	
	if (iter != endObj)
	{
		return true;
	}
	return false;
}

bool operator==(CandidateType cand, int id)
{
	return (cand.getID() == id);
}

void CandidateList::printHeader() const
{
	// Print Top of Table Before Results
	cout << right << setw(18) << setfill('*') << " FINAL"
		<< left << setw(21) << " RESULTS ";

	cout << left << setw(17) << setfill(' ') << "\n\nLAST"
		<< setw(10) << "FIRST"
		<< setw(5) << "TOTAL"
		<< right << setw(8) << "POS\n";

	cout << left << setw(15) << "NAME"
		<< setw(10) << "NAME"
		<< setw(5) << "VOTES"
		<< right << setw(8) << "#\n"
		<< setw(41) << setfill('_') << "_\n\n";
}

void CandidateList::printCandidate(list<CandidateType>::const_iterator iter, int rankPos) const
{ 
	iter->printID();
	cout << " - " << iter->getLastName()
		<< ", " << iter->getFirstName() << "\n";
}

void CandidateList::printLastCandidate() const
{
	list<CandidateType>::const_iterator iter = candidates.end();
	iter--;
	printCandidate(iter, 0);
}
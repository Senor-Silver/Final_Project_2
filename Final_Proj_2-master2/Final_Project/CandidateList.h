/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Sunday, May 3, 2020

		 CS A250
		 Project 1 - Part B
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

class CandidateList
{
public:
	// Default constructor
	CandidateList(){};

	// addCandidate
	void addCandidate(const CandidateType& candidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	// searchCandidate
	bool isEmpty() const;
	bool searchCandidate(int ID) const;

	// printCandidateName
	// printAllCandidates
	// printKingdomVotes
	// printCandidateTotalVotes
	void printCandidateName(int ID) const;
	void printAllCandidates() const;
	void printKingdomVotes(int ID, int kingdom) const;
	void printCandidateTotalVotes(int ID) const;
	void printLastCandidate() const;

	// Last Print and Destructors
	void printFinalResults() const;
	~CandidateList();

private:
	// searchCandidate
	//bool searchCandidate(int ID, Node*& ptrToCandidate) const;
	
	bool searchCandidate(int ID, std::list<CandidateType>::const_iterator firstObj) const;
	void printHeader() const;
	void printCandidate(std::list<CandidateType>::const_iterator iter, int rankPos) const;

	std::list<CandidateType> candidates;
};

#endif

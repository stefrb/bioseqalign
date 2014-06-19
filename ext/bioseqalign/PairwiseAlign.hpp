#ifndef PAIRWISE_ALIGN_HPP
#define PAIRWISE_ALIGN_HPP

#include <iostream>
#include <string>
#include <seqan/align.h>

#include "rice/String.hpp"
#include "rice/Array.hpp"

using namespace seqan;

typedef String<char> TSequence;                 // sequence type
typedef StringSet<TSequence> TStringSet;       // container for strings
typedef StringSet<TSequence, Dependent<> > TDepStringSet;   // dependent string set
typedef Graph<Alignment<TDepStringSet> > TAlignGraph;   // alignment graph

typedef Align<TSequence,ArrayGaps> TAlign;
typedef Row<TAlign>::Type TRow;

class PairwiseAlign {
protected:
  std::string seq1;
  std::string seq2;
  int score;
  TAlignGraph alignG;
  int matchScore;
  int mismatchScore;
  int indelScore;
  // return a ruby array of the alignment matrix string
  Rice::Array getArrayFromAlignStr(std::string alignMat);
  
public:
  PairwiseAlign();
  PairwiseAlign(std::string s1, std::string s2);
  //PairwiseAlign(std::string s1, std::string s2, int matchS, int mismatchS, int indelS);
  virtual ~PairwiseAlign() {}
  
  virtual void run() {}
  int getAlignScore() { return score; }
  //virtual std::string getAlignment() { return ""; }
  virtual Rice::Array getAlignment() { Rice::Array tmp; return tmp; }
  
  void setMatchScore(int mS) { matchScore = mS; }
  void setMismatchScore(int mS) { mismatchScore = mS; }
  void setIndelScore(int idS) { indelScore = idS; }

  std::string getSeq1() { return seq1; }
  std::string getSeq2() { return seq2; }
  
};


#endif

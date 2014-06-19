#include "FitAlign.hpp"

FitAlign::FitAlign() {}

FitAlign::FitAlign(std::string s1, std::string s2) : PairwiseAlign(s1, s2) { }

// unable to figure out how to properly overload constructor using RICE
//FitAlign::FitAlign(std::string s1, std::string s2, int matchS, int mismatchS, int indelS) : PairwiseAlign(s1, s2, matchS, mismatchS, indelS) {}

//std::string FitAlign::getAlignment() {
Rice::Array FitAlign::getAlignment() {
  TSequence tseq1 = seq1;
  TSequence tseq2 = seq2;

  TStringSet sequences;
  appendValue(sequences,tseq1);
  appendValue(sequences,tseq2);

  TAlignGraph alignG(sequences);
  
  // don't penalize gaps on begin/end of seq2
  globalAlignment(alignG, Score<int,Simple>(matchScore,mismatchScore,indelScore), AlignConfig<true, false, false, true>(), NeedlemanWunsch());

  /*
  std::stringstream ss;
  ss<<alignG;
  return ss.str();
  */
  std::string mat;
  convertAlignment(alignG, mat);
  return getArrayFromAlignStr(mat);
}


void FitAlign::run() {
  TSequence tseq1 = seq1;
  TSequence tseq2 = seq2;

  TStringSet sequences;
  appendValue(sequences,tseq1);
  appendValue(sequences,tseq2);

  TAlignGraph alignG(sequences);
  
  // don't penalize gaps on begin/end of seq2
  score = globalAlignment(alignG, Score<int,Simple>(matchScore,mismatchScore,indelScore), AlignConfig<true, false, false, true>(), NeedlemanWunsch());
  
}

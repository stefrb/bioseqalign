#include "PrefixSuffixAlign.hpp"

PrefixSuffixAlign::PrefixSuffixAlign() {}

PrefixSuffixAlign::PrefixSuffixAlign(std::string s1, std::string s2) : PairwiseAlign(s1, s2) { }

//std::string PrefixSuffixAlign::getAlignment() {
//Rice::Array PrefixSuffixAlign::getAlignmentArray() {
Rice::Array PrefixSuffixAlign::getAlignment() {
  TSequence tseq1 = seq1;
  TSequence tseq2 = seq2;

  TStringSet sequences;
  appendValue(sequences,tseq1);
  appendValue(sequences,tseq2);

  TAlignGraph alignG(sequences);
  
  // don't penalize gaps on begin/end of seq2
  globalAlignment(alignG, Score<int,Simple>(matchScore,mismatchScore,indelScore), AlignConfig<false, true, false, true>(), NeedlemanWunsch());

 
  std::string mat;
  convertAlignment(alignG, mat);
  //std::cout<<alignG<<std::endl;
  //std::cout<<mat<<std::endl;
  return getArrayFromAlignStr(mat);
  /*  
  Rice::Array tmp;
  int halfLen = mat.size()/2;
  tmp.push(mat.substr(0, halfLen));
  tmp.push(mat.substr(halfLen+1, halfLen));
  return tmp;
  */
  //return mat;
}


void PrefixSuffixAlign::run() {
  TSequence tseq1 = seq1;
  TSequence tseq2 = seq2;

  TStringSet sequences;
  appendValue(sequences,tseq1);
  appendValue(sequences,tseq2);

  TAlignGraph alignG(sequences);
  
  // don't penalize gaps on begin/end of seq2
  score = globalAlignment(alignG, Score<int,Simple>(matchScore,mismatchScore,indelScore), AlignConfig<false, true, false, true>(), NeedlemanWunsch());
  
}

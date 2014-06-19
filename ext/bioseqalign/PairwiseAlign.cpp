#include "PairwiseAlign.hpp"

PairwiseAlign::PairwiseAlign() {}

PairwiseAlign::PairwiseAlign(std::string s1, std::string s2) {
  seq1 = s1;
  seq2 = s2;  
  score = -10000;
  matchScore = 1;
  mismatchScore = -1;
  indelScore = -1;
}

// unable to properly figure out how to overload constructor when using RICE
// PairwiseAlign::PairwiseAlign(std::string s1, std::string s2, int matchS, int mismatchS, int indelS) {
//   seq1 = s1;
//   seq2 = s2;  
//   score = -10000;
//   matchScore = matchS;
//   mismatchScore = mismatchS;
//   indelScore = indelS;
// }

/**
 * given an alignment matrix string, split into two, and put in ruby array
 */
Rice::Array PairwiseAlign::getArrayFromAlignStr(std::string alignMat) {
  Rice::Array tmp;
  int halfLen = alignMat.size()/2;
  tmp.push(alignMat.substr(0, halfLen));
  tmp.push(alignMat.substr(halfLen, halfLen));
  return tmp;
}

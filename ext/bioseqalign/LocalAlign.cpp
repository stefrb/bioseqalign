// local alignment

#include "LocalAlign.hpp"

LocalAlign::LocalAlign() {}

LocalAlign::LocalAlign(std::string s1, std::string s2) : PairwiseAlign(s1, s2) { }

Rice::Array LocalAlign::getAlignment() {
  TAlign ali;
  resize(rows(ali), 2);
  assignSource(row(ali, 0), seq1);
  assignSource(row(ali, 1), seq2);
  
  //localAlignment(ali, Score<int,Simple>(matchScore,mismatchScore,indelScore), SmithWaterman());
  localAlignment(ali, Score<int>(matchScore,mismatchScore,indelScore), SmithWaterman());

  //std::cout<<row(ali, 0)<<std::endl;
  //std::cout<<row(ali, 1)<<std::endl;

  typedef Iterator<TRow>::Type TRowIterator;
  TRowIterator it = begin(row(ali, 0));
  TRowIterator itEnd = end(row(ali, 0));
  std::string s_row1 = "";
  for(; it != itEnd; ++it) {
    if(isGap(it)) s_row1 += "-";
    else s_row1 += (*it);
  }
  TRowIterator it2 = begin(row(ali, 1));
  TRowIterator itEnd2 = end(row(ali, 1));
  std::string s_row2 = "";
  for(; it2 != itEnd2; ++it2) {
    if(isGap(it2)) s_row2 += "-";
    else s_row2 += (*it2);
  }

  // std::cout<<s_row1<<std::endl;
  // std::cout<<s_row2<<std::endl;
  // std::cout<<ali<<std::endl;
  
  return getArrayFromAlignStr(s_row1+s_row2);
}


void LocalAlign::run() {
  TAlign ali;
  resize(rows(ali), 2);
  assignSource(row(ali, 0), seq1);
  assignSource(row(ali, 1), seq2);
  
  score = localAlignment(ali, Score<int,Simple>(matchScore,mismatchScore,indelScore), SmithWaterman());
}


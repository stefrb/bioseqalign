
#include <iostream>
#include <string>
#include <seqan/align.h>

#include "PairwiseAlign.hpp"

using namespace seqan;

class FitAlign : public PairwiseAlign {
public:
  FitAlign();
  FitAlign(std::string s1, std::string s2);
  //FitAlign(std::string s1, std::string s2, int matchS, int mismatchS, int indelS);
  virtual ~FitAlign() {}
  
  virtual void run();
  //virtual std::string getAlignment();
  virtual Rice::Array getAlignment();
  
};


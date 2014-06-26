// global alignment

#include <iostream>
#include <string>
#include <seqan/align.h>

#include "PairwiseAlign.hpp"

using namespace seqan;

class GlobalAlign : public PairwiseAlign {
public:
  GlobalAlign();
  GlobalAlign(std::string s1, std::string s2);
  virtual ~GlobalAlign() {}
  
  virtual void run();
  virtual Rice::Array getAlignment();
  
};

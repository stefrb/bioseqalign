// local alignment

#include <iostream>
#include <string>
#include <seqan/align.h>

#include "PairwiseAlign.hpp"

using namespace seqan;

class LocalAlign : public PairwiseAlign {
public:
  LocalAlign();
  LocalAlign(std::string s1, std::string s2);
  virtual ~LocalAlign() {}
  
  virtual void run();
  virtual Rice::Array getAlignment();
  
};


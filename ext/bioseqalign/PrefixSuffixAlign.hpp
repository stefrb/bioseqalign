/**
 * Perform prefix-suffix alignment, aligning the prefix of seq1
 * with the suffix of seq2
 * ex:  seq1:  --------YYYYYYYZZZZZZ
 *      seq2:  XXXXXXXXYYYYYYY------
 */

#include <iostream>
#include <string>
#include <seqan/align.h>

#include "PairwiseAlign.hpp"

using namespace seqan;


class PrefixSuffixAlign : public PairwiseAlign {
public:
  PrefixSuffixAlign();
  PrefixSuffixAlign(std::string s1, std::string s2);
  virtual ~PrefixSuffixAlign() {}
  
  virtual void run();
  //virtual std::string getAlignment();
  //Rice::Array getAlignmentArray();
  virtual Rice::Array getAlignment();
  
};



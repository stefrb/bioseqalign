#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
//#include "PairwiseAlign.hpp"
#include "FitAlign.hpp"
#include "PrefixSuffixAlign.hpp"
#include "LocalAlign.hpp"
#include "GlobalAlign.hpp"

using namespace Rice;

extern "C"

//void Init_FitAlign()
void Init_SeqAlign()
{
  Data_Type<PairwiseAlign> rb_cPairwiseAlign = define_class<PairwiseAlign>("PairwiseAlign")
    .define_constructor(Constructor<PairwiseAlign>())
    .define_constructor(Constructor<PairwiseAlign,std::string,std::string>())
    //.define_constructor(Constructor<PairwiseAlign,std::string,std::string,int,int,int>())
    .define_method("getAlignScore", &PairwiseAlign::getAlignScore)
    .define_method("getSeq1", &PairwiseAlign::getSeq1)
    .define_method("getSeq2", &PairwiseAlign::getSeq2)
    .define_method("run", &PairwiseAlign::run)
    .define_method("getAlignment", &PairwiseAlign::getAlignment)
    .define_method("setMatchScore", &PairwiseAlign::setMatchScore)
    .define_method("setMismatchScore", &PairwiseAlign::setMismatchScore)
    .define_method("setIndelScore", &PairwiseAlign::setIndelScore);
  Data_Type<FitAlign> rb_cFitAlign = define_class<FitAlign,PairwiseAlign>("FitAlign")
    .define_constructor(Constructor<FitAlign>())
    .define_constructor(Constructor<FitAlign,std::string,std::string>())
    //.define_constructor(Constructor<FitAlign,std::string,std::string,int,int,int>())
    .define_method("run", &FitAlign::run)
    .define_method("getAlignment", &FitAlign::getAlignment);
  Data_Type<PrefixSuffixAlign> rb_cPrefixSuffixAlign = define_class<PrefixSuffixAlign,PairwiseAlign>("PrefixSuffixAlign")
    .define_constructor(Constructor<PrefixSuffixAlign>())
    .define_constructor(Constructor<PrefixSuffixAlign,std::string,std::string>())
    .define_method("run", &PrefixSuffixAlign::run)
    .define_method("getAlignment", &PrefixSuffixAlign::getAlignment);
  Data_Type<LocalAlign> rb_cLocalAlign = define_class<LocalAlign,PairwiseAlign>("LocalAlign")
    .define_constructor(Constructor<LocalAlign>())
    .define_constructor(Constructor<LocalAlign,std::string,std::string>())
    .define_method("run", &LocalAlign::run)
    .define_method("getAlignment", &LocalAlign::getAlignment);
  Data_Type<GlobalAlign> rb_cGlobalAlign = define_class<GlobalAlign,PairwiseAlign>("GlobalAlign")
    .define_constructor(Constructor<GlobalAlign>())
    .define_constructor(Constructor<GlobalAlign,std::string,std::string>())
    .define_method("run", &GlobalAlign::run)
    .define_method("getAlignment", &GlobalAlign::getAlignment);
}

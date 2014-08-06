require_relative 'test_helper'

class TestFitAlign < Test::Unit::TestCase
  include SeqAlign
  #
  # test basic get method
  #
  def test_pairwise_getseq()
    sa = PairwiseAlign.new("TCGA", "TCGA")
    assert_equal sa.getSeq1, "TCGA"
  end
  #
  # test using default scoring
  #
  def test_fitAlign_score()
    fa = FitAlign.new("AAAAAAAATCGAGGG", "TCGA")
    fa.run
    assert_equal fa.getAlignScore, 4
  end
  #
  # test using a user-defined scoring for matches
  #
  def test_fitAlign_score_nondefault()
    fa = FitAlign.new("AAAAAAAATCGAGGG", "TCGA")
    fa.setMatchScore(2)
    fa.run
    assert_equal fa.getAlignScore, 8
  end

end  


class TestPrefixSuffixAlign < Test::Unit::TestCase
  include SeqAlign
  
  #
  # test simple case of prefix-suffix alignment
  #
  def test_prefix_suffix_simple()
    psa = PrefixSuffixAlign.new("AAAAABBBBB", "CCCCCAAAAA")
    psa.run
    a = psa.getAlignment
    assert_equal (a[0] == "-----AAAAABBBBB"), true
    assert_equal (a[1] == "CCCCCAAAAA-----"), true
  end
  
end

class TestLocalAlign < Test::Unit::TestCase
  include SeqAlign
  
  #
  # test simple case of prefix-suffix alignment
  #
  def test_local_simple()
    la = LocalAlign.new("AAAAACCCBBBBB", "CCC")
    la.run
    a = la.getAlignment
    assert_equal (a[0] == "CCC"), true
    assert_equal (a[1] == "CCC"), true
    s = la.getAlignScore
    assert_equal (s == 3), true
  end
  
end

class TestGlobalAlign < Test::Unit::TestCase
  include SeqAlign
  
  #
  # test simple case of prefix-suffix alignment
  #
  def test_global_simple()
    la = GlobalAlign.new("AAAAACCCBBBBB", "AAAAACBBBBBB")
    la.run
    a = la.getAlignment
    assert_equal (a[0] == "AAAAACCCBBBBB"), true
    assert_equal (a[1] == "AAAAA-CBBBBBB"), true
    s = la.getAlignScore
    assert_equal (s == 9), true
  end
  
end

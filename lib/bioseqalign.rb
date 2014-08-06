require 'bioseqalign/SeqAlign'

module BioSeqAlign

  include SeqAlign

  #
  # fit seq2 into seq1, returns the score 
  #
  def BioSeqAlign.fitAlignScore(seq1, seq2, match=1, mismatch=-1, indel=-1)
    fa = FitAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignScore
  end  
  #
  # fit seq2 into seq1, returns alignment
  #
  # example:
  # [input]:: seq1 = <tt>AAAAAAAAGCTGAAAAAAAA</tt>
  #
  #           seq2 = <tt>GCTG</tt>
  #
  # [output]:: <tt>["AAAAAAAAGCTGAAAAAAAA", "--------GCTG--------"]</tt>
  #
  # result of fitting alignment
  #
  # seq1: <tt>AAAAAAAAGCTGAAAAAAAA</tt>
  #
  # seq2: <tt>--------GCTG--------</tt>
  #
  def BioSeqAlign.fitAlignStr(seq1, seq2, match=1, mismatch=-1, indel=-1)
    fa = FitAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignment
  end
  #
  # prefix-suffix alignment, returns score. Prefix of seq2 aligned with
  # suffix of seq1
  #
  def BioSeqAlign.prefixSuffixAlignScore(seq1, seq2,  match=1, mismatch=-1, indel=-1)
    fa = PrefixSuffixAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignScore
  end
  #
  # prefix-suffix alignment, returns alignment. Prefix of seq2 aligned with
  # suffix of seq1
  #
  # example:
  # 
  # [input]:: seq1 = <tt>GGGGGGGGAAAAA</tt>
  #
  #           seq2 = <tt>AAAAAACTGATAC</tt>
  #
  # [output]:: <tt>["GGGGGGGGAAAAA--------", "--------AAAAAACTGATAC"]</tt>
  #
  # result of prefix-suffix alignment
  #
  # seq1: <tt>GGGGGGGGAAAAA--------</tt>
  #
  # seq2: <tt>--------AAAAAACTGATAC</tt>
  #
  def BioSeqAlign.prefixSuffixAlignStr(seq1, seq2,  match=1, mismatch=-1, indel=-1)
    fa = PrefixSuffixAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignment
  end
  #
  # local alignment of seq1 and seq2, returns score.
  #
  def BioSeqAlign.localAlignScore(seq1, seq2,  match=1, mismatch=-1, indel=-1)
    fa = LocalAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignScore
  end
  #
  # local alignment of seq1 and seq2, returns alignment.
  #
  # example:
  # 
  # [input]:: seq1 = <tt>CTGAGTCGATAA</tt>
  #
  #           seq2 = <tt>GGGGTCGATTTT</tt>
  #
  # [output]:: <tt>["GTCGAT", "GTCGAT"]</tt>
  #
  # result of local alignment
  #
  # seq1: <tt>GTCGAT</tt>
  #
  # seq2: <tt>GTCGAT</tt>
  #
  def BioSeqAlign.localAlignStr(seq1, seq2,  match=1, mismatch=-1, indel=-1)
    fa = LocalAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignment
  end
  #
  # global alignment of seq1 and seq2, returns score.
  #
  def BioSeqAlign.globalAlignScore(seq1, seq2,  match=1, mismatch=-1, indel=-1)
    fa = GlobalAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignScore
  end
  #
  # global alignment of seq1 and seq2, returns alignment.
  #
  # example:
  # 
  # [input]:: seq1 = <tt>CTGAGTCGATAA</tt>
  #
  #           seq2 = <tt>GGGGTCGATTTT</tt>
  #
  # [output]:: <tt>["CTGAGTCGA-TA", "AGGGGTCGATTT"]</tt>
  #
  # result of global alignment
  #
  # seq1: <tt>CTGAGTCGA-TA</tt>
  #
  # seq2: <tt>AGGGGTCGATTT</tt>
  #
  def BioSeqAlign.globalAlignStr(seq1, seq2,  match=1, mismatch=-1, indel=-1)
    fa = GlobalAlign.new(seq1, seq2)
    fa.setMatchScore(match)
    fa.setMismatchScore(mismatch)
    fa.setIndelScore(indel)
    fa.run
    fa.getAlignment
  end
    
end

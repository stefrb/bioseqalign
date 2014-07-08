require './SeqAlign'

sa = PairwiseAlign.new("TCGA", "TCGA")
puts sa.getSeq1

#__END__
fa = FitAlign.new("AAAAAAAATCGAGGG", "TCGA")
fa.setMatchScore(2)
fa.setMismatchScore(-1)
fa.setIndelScore(-1)
puts fa.getSeq1
fa.run
puts fa.getAlignScore
puts fa.getAlignment


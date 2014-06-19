# BioSeqAlign
A gem to perform pairwise sequence alignment using the seqan library

## Requirements

This gem relies on the following gems
* [RICE] (https://rubygems.org/gems/rice)
* [SeqAn] (https://www.seqan.de/)

## Install

Once you build/install the gem, you can start using it. If you want to perform a fitting alignment, you can try the following.

### Example
    
    require 'bioseqalign'

    BioSeqAlign.fitAlignScore(seqA, seqB)


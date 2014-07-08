# BioSeqAlign
A gem to perform pairwise sequence alignment using the seqan library. Currently, only local alignment, prefix-suffix alignment (overhang), and fitting alignment (semi-global) are implemented.
[![Gem Version](https://badge.fury.io/rb/bioseqalign.svg)](http://badge.fury.io/rb/bioseqalign)

## Why use this gem?
If you need to perform pairwise alignment in Ruby, use the align gem (https://github.com/justfalter/align), it's a very nice Ruby implementation. However, if you need a faster alternative, i.e., performing many alignments, bioseqalign can help. Since it uses SeqAn C++ library, it can be much faster than pure Ruby. Alternatively, if you need to perform fitting or prefix-suffix alignment, these are supported without modification.

## Requirements

This gem relies on the following gems/libraries
* [RICE] (https://rubygems.org/gems/rice)
* [SeqAn] (https://www.seqan.de/)

## Install

This gem requires SeqAn to be installed on the system, on ubuntu, this can be done by

```
apt-get install seqan-dev
```

To install the gem, run

```ruby
gem install bioseqalign
```

## Example
Once you build/install the gem, you can start using it. If you want to perform a fitting alignment, you can try the following.

```ruby    
require 'bioseqalign'

BioSeqAlign.fitAlignStr("AAAAAAAAGCTGAAAAAAAA", "GCTG")
```

Which would produce the following output
  
    ["AAAAAAAAGCTGAAAAAAAA", "--------GCTG--------"]

If you just want the score

```ruby
BioSeqAlign.fitAlignScore(seqA, seqB)
```

Which returns a value of

    4

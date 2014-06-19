# BioSeqAlign
A gem to perform pairwise sequence alignment using the seqan library

## Requirements

This gem relies on the following gems/libraries
* [RICE] (https://rubygems.org/gems/rice)
* [SeqAn] (https://www.seqan.de/)

## Install

Build the gem, it is not on https://rubygems.org

```ruby
gem build ./bioseqalign.gemspec
```

Then install the gem
```ruby
gem install ./bioseqalign-0.0.1.gem
```

## Example
Once you build/install the gem, you can start using it. If you want to perform a fitting alignment, you can try the following.

```ruby    
require 'bioseqalign'

BioSeqAlign.fitAlignScore(seqA, seqB)

BioSeqAlign.fitAlignStr(seqA, seqB)
```



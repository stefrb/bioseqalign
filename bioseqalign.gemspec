$LOAD_PATH.unshift File.expand_path("../lib", __FILE__)
require 'bioseqalign/version'

Gem::Specification.new do |s|
  s.name        = 'bioseqalign'
  s.version     = BioSeqAlign::VERSION
  s.date        = Time.now.to_s.split(" ")[0]
  s.summary     = "Pairwise sequence alignment using seqan"
  s.description = "A simple gem to perform fast pairwise sequence alignment using seqan"
  s.authors     = ["Stefano R.B."]
  s.email       = 'stefano.rb@gmail.com'
  s.files = Dir['lib/**/*.rb'] + Dir['bin/*'] + Dir['ext/**/*']
  s.require_paths = ['lib', 'ext']
  s.homepage    = 'https://github.com/stefrb/bioseqalign'
  s.license 	= 'MIT'
  s.extensions = [ 'ext/bioseqalign/extconf.rb' ]
  s.add_dependency 'rice', '~> 2.1'
end

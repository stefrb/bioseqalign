Gem::Specification.new do |s|
  s.name        = 'bioseqalign'
  s.version     = '0.0.1'
  s.date        = '2014-06-04'
  s.summary     = "Pairwise sequence alignment using seqan"
  s.description = "A simple gem to perform fast pairwise sequence alignment using seqan"
  s.authors     = ["Stefano R.B."]
  s.email       = 'stefano.rb@gmail.com'
  s.files = Dir['lib/**/*.rb'] + Dir['bin/*'] + Dir['ext/**/*']
  s.require_paths = ['lib', 'ext']
  s.homepage    = 'http://rubygems.org/gems/bioseqalign'
  s.license 	= 'MIT'
  s.extensions = [ 'ext/bioseqalign/extconf.rb' ]
  s.add_dependency 'rice'
end

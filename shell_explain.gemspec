# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'shell_explain/version'

Gem::Specification.new do |spec|
  spec.platform      = Gem::Platform::RUBY
  spec.name          = "shell_explain"
  spec.version       = ShellExplain::VERSION
  spec.authors       = ["blackanger"]
  spec.email         = ["blackanger.z@gmail.com"]
  spec.description   = %q{explainshell.com input from terminal}
  spec.summary       = %q{explainshell.com for terminal}
  spec.homepage      = "https://github.com/ZhangHanDong/shell_explain"
  spec.license       = "MIT"

  spec.extensions    = %w[ext/my_malloc/extconf.rb]
  spec.files         = `git ls-files`.split($/)
  spec.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_dependency "ansi"
  spec.add_dependency "nokogiri"

  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
end

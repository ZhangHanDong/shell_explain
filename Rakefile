require "bundler/gem_tasks"
require 'rake/extensiontask'
spec = Gem::Specification.load('shell_explain.gemspec')
Rake::ExtensionTask.new('my_test', spec) do |ext|
	ext.lib_dir = "lib/my_test"
end

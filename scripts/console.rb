#!/usr/bin/env ruby

require 'pry'


$: << "../../lib" << "./lib"
require "shell_explain"


puts "Loading SE environment ... "

Pry.start
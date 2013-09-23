require "shell_explain/version"
require 'net/http'
require 'nokogiri'

class ShellExplain

  class << self
    def get_data(cmd)
    	uri = URI("#{uri}#{URI::escape(cmd).gsub(/&/, '%26')}")
    	html = Net::HTTP.get_response(uri).body
    	Nokogiri::HTML(html)
    end

    def get_command(doc)
      doc.xpath("//span[@helpref]").inject([]) do|cmds, node|
        cmds << node.text
      end
    end

    def get_explain(doc)
      data = doc.xpath("//table[@id='help']//pre").inject([]) do|exps, node|
        exps << node.children.text
      end
      data
    end

  end

end
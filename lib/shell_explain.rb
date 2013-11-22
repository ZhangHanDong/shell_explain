require "shell_explain/version"
require 'net/http'
require 'nokogiri'
require 'cgi'


module ShellExplain
  class Site

    class << self
      def get_data(cmd)
        explain_shell_url = "http://explainshell.com/explain?cmd="
        uri = URI("#{explain_shell_url}#{CGI.escape(cmd)}")
        html = Net::HTTP.get_response(uri).body
        Nokogiri::HTML(html)
      end

      #{command: help-num}
      def get_command(doc)
        doc.xpath("//span[@helpref]").inject({}) do|cmds, node|
          cmds[node.text] = node.attributes["helpref"].value
          cmds
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
end